#!/usr/bin/env python3
# -*- coding: utf-8 -*-
#
# michael a.g. aïvázis
# california institute of technology
# (c) 1998-2018 all rights reserved
#

# externals
import os
import sys
import platform
import subprocess


# log a message with the user, using {journal} if available
def complain(msg):
    """
    Print error messages
    """
    # if there is journal
    try:
        # use it
        import journal
        journal.error('mm').log(msg)
    # otherwise
    except ImportError:
        # print the error message
        print('mm:', msg, file=sys.stderr)
    # return
    return

# uniq
def uniq(sequence):
    """
    Filter out duplicates in {sequence}
    """
    # initialize the known set
    known = set()
    # go through the items in sequence
    for item in sequence:
        # skip this one if we have seen it before
        if item in known: continue
        # otherwise hand it to the caller
        yield item
        # and add it to the known pile
        known.add(item)
    # all done
    return


# support classes
class Shell:
    """Encapsulation of executing subcommands and harvesting their {stdout}"""

    @classmethod
    def str(cls, settings):
        """
        Launch a subprocess using {settings} as the pipe configuration, and harvest a string
        """
        # the default value
        result = None
        # make a pipe
        with subprocess.Popen(**settings) as pipe:
            # grab the output
            result = pipe.stdout.read().strip()
        # otherwise, return a blank string
        return result


class Package:
    """
    Meta data for external dependencies
    """
    name = None
    environ = None
    optional = False
    path = ''
    ldpath = ''

    def __init__(self, name, optional=False):
        self.name = name
        self.optional = optional
        self.environ = {}
        return


class Options(dict):
    """
    Command line processing
    """

    # public data
    args = None
    options = {
        # command that affect the build
        'bldroot', 'prefix', 'target', 'makefile',
        # display
        'dry', 'env', 'show', 'quiet',
        # utilities for setting up the user environment
        'paths',
        # installation control
        'host', 'home', 'root',
        # internal and not yet implemented
        'recursive', 'xml'
        }

    # meta methods
    def __init__(self, **kwds):
        super().__init__(**kwds)
        # the list of arguments
        args = []
        # go through the commands
        for index, arg in enumerate(sys.argv):
            # all {mm.py} command line arguments are in long form
            if not arg.startswith('--'):
                # add it to the pass-through pile
                args.append(arg)
                # and grab the next one
                continue
            # this might be mine
            try:
                # to split it on the '=' sign
                name, value = arg[2:].split('=')
            # if there aren't exactly two parts
            except ValueError:
                # extract the command
                name = arg[2:]
                # if it is is one of mine
                if name in self.options:
                    # assume the intended value is {True}
                    self[name] = True
                # otherwise
                else:
                    # add it to the pass-through pile
                    args.append(arg)
                # and grab the next onw
                continue
            # if it's not one of mine
            if name not in self.options:
                # add it to the pass-through pile
                args.append(arg)
                # and grab the next onw
                continue
            # otherwise
            self[name] = value
        # save
        self.args = tuple(args)
        # all done
        return


class Make:
    """The build tool"""
    gnumake = os.environ.get('GNU_MAKE', 'make')
    defaultOptions = ['--environment-overrides', '--warn-undefined-variables']
    argv = None

    @property
    def command(self):
        return " ".join(self.argv)


    # meta methods
    def __init__(self):
        # initialize the command line arguments to {make}
        argv = [ self.gnumake ]
        # look for other default options
        try:
            # from the environment, if there
            extra = os.environ['MM_MAKE_OPTIONS'].split()
        # or
        except KeyError:
            # form my default list
            extra = self.defaultOptions
        # add them to the pile
        argv.extend(extra)
        # save it
        self.argv = argv
        # all done
        return


class User:
    """The user that is invoking {mm}"""
    name = os.environ.get('LOGNAME') or os.popen('whoami').read().strip()
    home = os.environ.get('HOME') or os.path.expanduser('~')
    environment = {}

    @property
    def mm(self):
        """
        Build and return the path to the user's {.mm} directory
        """
        # get my home
        home = self.home
        # if i don't know where that is, bail
        if not home: return None
        # assemble the location
        mm = os.path.join(home, '.mm')
        # if the directory exists
        if os.path.isdir(mm):
            # return it
            return mm
        # bail
        return None


class Host:
    """Host information"""
    system, name, release, version, architecture, processor = platform.uname()


class Project:
    """Project information"""

    name = ''
    root = ''
    marker = '.mm'
    environment = None

    # support
    @classmethod
    def locateRoot(cls):
        # initialize the candidate directory
        candidate = os.getcwd()
        # loop until we reach the root of the filesystem
        while candidate != os.path.sep:
            # if the magic file is here
            if os.path.exists(os.path.join(candidate, cls.marker)):
                # got it
                return candidate
            # otherwise, split the path and try again
            candidate, _ = os.path.split(candidate)
        # if we get here, the search has failed
        return os.path.sep

    # meta methods
    def __init__(self):
        # self.name = Shell.str(
            # settings={
                # 'args': ['bzr', 'nick'],
                # 'executable': 'bzr',
                # 'stdout': subprocess.PIPE, 'stderr': subprocess.PIPE,
                # 'universal_newlines': True,
                # 'shell': False
                # }
            # )
        self.environment = {}
        self.root = self.locateRoot()

        # if this project is under bzr
        if os.path.exists(os.path.join(self.root, '.bzr')):
            # attempt to figure out the branch nickname
            try:
                # use it as the project name
                self.name = Shell.str(
                    settings={
                        'args': ['bzr', 'nick'],
                        'executable': 'bzr',
                        'stdout': subprocess.PIPE, 'stderr': subprocess.PIPE,
                        'universal_newlines': True,
                        'shell': False
                        }
                    )
            # if that fails
            except FileNotFoundError:
                # use the root directory name
                _, self.name = os.path.split(self.root)
        # if we can't get this information from the source control system
        else:
            # use the root directory name
            _, self.name = os.path.split(self.root)

        # all done
        return


class Compiler:
    """The choice of compilers for the supported languages"""

    suite = ''
    c = ''
    cxx = ''
    fortran = ''


class Build:
    """The target build information"""

    user = None
    machine = 'unknown'
    defaultTarget = 'debug'

    # support
    @classmethod
    def getStandardTarget(cls, host):
        """Derive the {mm} target name from the machine characteristics"""
        # check whether the corresponding environment variable is set
        try:
            # and if so return it
            return os.environ['BLD_STANDARD_TARGET']
        # otherwise, there's more to do
        except KeyError: pass

        # for darwin
        if host.system == 'Darwin':
            # get the version and architecture
            release, _, arch = platform.mac_ver()
            # reduce the version down to its essentials
            family = release.split('.')[0]
            # it all gets handled by the same target file
            return 'Darwin-{}.x_{}'.format(family, arch)
        # for linux
        if host.system == 'Linux':
            # get the version
            version = host.release.split('.')[0]
            # build the platform marker
            return 'Linux-{}.x_{}'.format(version, host.architecture)
        # otherwise
        return 'unknown'

    def getUserTargets(cls, options):
        """Build a list with the user specified build targets"""
        # first check for a command line argument
        try:
            targets = options['target']
        # if the lookup failed
        except KeyError:
            # check for an environment variable
            targets = os.environ.get('TARGET')
        # the setting should be a comma separated list of options
        return (targets or cls.defaultTarget).split(',')


    def __init__(self, user, host, options):
        self.machine = self.getStandardTarget(host)
        self.user = self.getUserTargets(options)
        return


class Installer:
    """Information about the installation target"""

    host = None
    user = None
    home = None
    root = None

    def __init__(self, options):
        self.host = options.get('host')
        self.user = options.get('user')
        self.home = options.get('home')
        self.root = options.get('root')
        return


class Builder:
    """The {mm} wrapper"""

    mm = "{} {}".format(sys.executable, os.path.abspath(sys.argv[0]))
    mmdef = os.path.split(__file__)[0]
    home = os.path.abspath(os.path.join(mmdef, os.pardir))
    directory = os.getcwd()
    makefile = 'Make.mm'
    includes = ['make', 'target', 'compiler', 'platform', 'external']

    requirements = None

    dry = False
    envonly = False
    show = True
    quiet = False
    exportPaths = True

    environ = {}
    prefix = '' # EXPORT_ROOT
    bldroot = '' # BLD_ROOT

    options = Options()
    make = Make()
    user = User()
    host = Host()
    compiler = Compiler()
    project = Project()
    build = Build(user, host, options)
    installer = Installer(options)

    # support
    def getLocalMakefile(self):
        """Deduce the name and location of the local makefile"""
        # get the options
        options = self.options
        # first, check the command line
        try:
            makefile = options['makefile']
        # if the lookup failed
        except KeyError:
            # check for an environment setting
            makefile = os.environ.get('LOCAL_MAKEFILE', self.makefile)

        # get the cwd directory
        cwd = os.getcwd()
        # locate the makefile
        location = self.locate(target=makefile)

        # if it's not in this directory
        if location != cwd and not self.quiet:
            # let the user know
            msg = 'warning: no makefile {!r} in {!r}'.format(makefile, cwd)
            complain(msg)
            # if we have found one
            if location:
                # tell the user what we are doing
                msg = 'warning: found one in {!r}; launching the build from there'.format(location)
                complain(msg)

        # return it
        return (location, makefile) if location else (None,'')


    def locate(self, target):
        # initialize the candidate directory
        candidate = os.getcwd()
        # get the root of the project
        root = self.project.root
        # loop until we reach the root of the project
        while candidate.startswith(root):
            # if the magic file is here
            if os.path.exists(os.path.join(candidate, target)):
                # got it
                return candidate
            # otherwise, split the path and try again
            candidate, _ = os.path.split(candidate)
        # if we get here, the search has failed
        return

    def getBuildRoot(self):
        """
        Deduce the desired location of the temporary files generated during the build
        """
        # get the options
        options = self.options
        # first, check the command line
        try:
            return options['bldroot']
        # if it failed, no worries
        except KeyError: pass

        # next, check for an environment variable
        try:
            return os.environ['BLD_ROOT']
        # if not there, no worries
        except KeyError: pass

        # if we know the project root directory
        if self.project.root:
            # push the build products in a subdirectory
            return os.path.join(self.project.root, 'builds')
        # if the user has a special directory for development activities
        try:
            return os.path.join(*filter(None, (os.environ['DV_DIR'], 'builds', self.project.name)))
        # if not there
        except KeyError:
            # last resort: the home directory
            if self.user.home:
                # push the build products in a subdirectory
                return os.path.join(*filter(None, (self.user.home, 'builds', self.project.name)))
        # just give up
        if not self.quiet:
            complain(msg='error: could not figure out where to place the build products')
        # and return an empty string
        return ''


    def getExportRoot(self):
        """
        Deduce the desired location for installing the build products
        """
        # get the options
        options = self.options
        # first, check the command line
        try:
            return options['prefix']
        # if it failed, no worries
        except KeyError: pass

        # next, check for an environment variable
        try:
            return os.environ['EXPORT_ROOT']
        # if not there
        except KeyError:
            # no worries
            pass

        # if we know the project root directory
        if self.project.root:
            # push the build products in a subdirectory
            return os.path.join(self.project.root, 'products')
        # if the user has a special directory for installed products
        try:
            return os.path.join(
                *filter(None, (os.environ['USER_TOOLS_DIR'], self.project.name)))
        # if not there
        except KeyError:
            # last resort: the home directory
            if self.user.home:
                # push the build products in a subdirectory
                return os.path.join(*filter(None, (self.user.home, 'tools', self.project.name)))
        # just give up
        if not self.quiet:
            msg = 'error: could not figure out where to install the build products'
            complain(msg)
        # and return an empty string
        return ''


    def getProjectRequirements(self):
        """
        Look for the set of external packages this project depends on
        """
        # get the project
        project = self.project
        # if we don't know where the source root is
        if not project.root:
            # we have no requirements
            return {}
        # otherwise, build the path to the requirements file
        reqfile = os.path.join(project.root, project.marker, 'project.py')
        # and load the symbols
        symbols = self._loadSymbols(path=reqfile)
        # attempt to
        try:
            # get the requirements factory
            factory = symbols['requirements']
        # if not there
        except KeyError:
            # no recovery possible
            return {}
        # otherwise, invoke it and return its result
        return factory(package=Package)


    def loadPlatformOptions(self):
        """
        Load the platform specific options
        """
        # get the project
        project = self.project
        # if we know where the source root is
        if project.root:
            # build the path to the platform options
            optfile = os.path.join(project.root, project.marker, 'platforms.py')
            # look for the platform specific file and have it decorate the build
            self._decorate(optfile, category='platform')
        # all done
        return


    def loadProjectOptions(self):
        """
        Load the project specific options
        """
        # get the project
        project = self.project
        # if we know where the source root is
        if project.root:
            # build the path to the platform options
            optfile = os.path.join(project.root, project.marker, 'project.py')
            # look for the project file and have it decorate the build
            self._decorate(optfile, category='project')
        # all done
        return


    def loadHostOptions(self):
        """
        Load the host specific options
        """
        # get the project
        project = self.project
        # if we know where the source root is
        if project.root:
            # build the path to the host options
            optfile = os.path.join(project.root, project.marker, 'hosts.py')
            # look for the host file and have it decorate the build
            self._decorate(optfile, category='host')
        # all done
        return


    def loadDeveloperOptions(self):
        """
        Load the developer specific options
        """
        # get the uset
        user = self.user
        # if we know where the user's home directory is
        if user.home:
            # build the path to the developer defaults
            optfile = os.path.join(user.home, '.mm', user.name+'.py')
            # look for the developer specific file and have it decorate the build
            self._decorate(optfile, category='developer')

        # get the project
        project = self.project
        # if we know where the source root is
        if project.root:
            # build the path to the developer options
            optfile = os.path.join(project.root, project.marker, 'developers.py')
            # look for the developer specific file and have it decorate the build
            self._decorate(optfile, category='developer')
        # all done
        return


    def createDirectories(self):
        """
        Create the necessary directories
        """
        # first, bldroot
        bldroot = self.bldroot
        # on success
        if bldroot and not os.path.exists(bldroot):
            # create the directory

            if not self.quiet:
                complain(msg='warning: creating bldroot directory at {!r}'.format(bldroot))
            if not self.dry:
                os.makedirs(bldroot)
            else:
                if not self.quiet: complain(msg='info: dry run')
        # next, the installation directory
        prefix = self.prefix
        # on success
        if prefix and not os.path.exists(prefix):
            # create the directory
            if not self.quiet:
                complain(msg='warning: creating prefix directory at {!r}'.format(prefix))
            # if this is a dry run
            if not self.dry:
                os.makedirs(prefix)
            else:
                if not self.quiet: complain(msg='info: dry run')
        # all done
        return


    def setEnvironment(self):
        """
        Transfer the build settings to environment variables used by the {config} makefiles
        """
        # initialize
        env = {}

        # the variables used to locate {mm}
        env['MM'] = '{} --recursive=on'.format(self.mm)
        env['MAKE'] = self.mm
        env['MKCMD'] = self.make.command
        # the name of the local makefile
        env['LOCAL_MAKEFILE'] = self.makefile
        # the directories
        env['BLD_CONFIG'] = self.home
        env['BLD_ROOT'] = self.bldroot
        env['EXPORT_ROOT'] = self.prefix
        env['PROJ_ROOT'] = self.project.root
        env['PROJ_CONFIG'] = os.path.join(self.project.root, self.project.marker)
        # the user
        env['DEVELOPER'] = self.user.name
        # the targets
        env['BLD_USER_TARGET'] = ' '.join(self.build.user)
        env['BLD_STANDARD_TARGET'] = self.build.machine
        env['TARGET'] = ','.join(self.build.user)
        env['TARGETS'] = ' '.join([self.build.machine] + self.build.user)
        env['TARGET_TAG'] = self.build.machine + '-' + ','.join(self.build.user)

        # install/live target control
        if self.installer.host: env['PROJ_LIVE_HOST'] = self.installer.host
        if self.installer.user: env['PROJ_LIVE_USER'] = self.installer.user
        if self.installer.home: env['PROJ_LIVE_HOME'] = self.installer.home
        if self.installer.root: env['PROJ_LIVE_ROOT'] = self.installer.root

        # {mm} control
        env['MM_STOP'] = '1'
        # env['XML']

        # machine info
        env['MM_PLATFORM'] = self.host.system.lower()
        env['MM_ARCH'] = self.host.architecture
        env['MM_HOSTNAME'] = self.host.name
        # project specific variables
        env.update(self.project.environment)
        # developer specific variables
        env.update(self.user.environment)

        # compiler control
        # adjust the suite that provides defaults for all supported languages
        if self.compiler.suite: env['TARGET_COMPILER'] = self.compiler.suite
        # adjust the C compiler
        if self.compiler.c: env['TARGET_CC'] = self.compiler.c
        # adjust the C++ compiler
        if self.compiler.cxx: env['TARGET_CXX'] = self.compiler.cxx
        # adjust the fortran compiler
        if self.compiler.fortran: env['TARGET_F77'] = self.compiler.fortran

        # initialize path and ldpath for the project requirements
        reqpath = []
        reqldpath = []
        # add the environment from the project requirements
        for package in self.requirements.values():
            # grab the environment
            for name, value in package.environ.items():
                # place its variables in the environment
                env[name] = value
            # adjust the runtime
            reqpath.append(package.path)
            reqldpath.append(package.ldpath)

        # adjust the python path
        pythonpath = list(os.environ.get('PYTHONPATH', '').split(os.pathsep))
        # we deposit packages here
        pkghome = os.path.join(self.prefix, 'packages')
        # if the place where python packages are deposited is not in this list
        if pkghome not in pythonpath:
            # adjust it
            pythonpath = filter(None, [pkghome] + pythonpath)
        # set it
        env['PYTHONPATH'] = os.pathsep.join(pythonpath)

        # adjust the execution path
        path = list(os.environ.get('PATH', '').split(os.pathsep))
        # we deposit binaries here
        binhome = os.path.join(self.prefix, 'bin')
        # extend it
        path = filter(None, [binhome] + reqpath + path)
        # trim it and set it
        env['PATH'] = os.pathsep.join(uniq(path))

        # adjust the ld library path
        ldpath = list(os.environ.get('LD_LIBRARY_PATH', '').split(os.pathsep))
        # we deposit shared objects here
        sharedhome = os.path.join(self.prefix, 'lib')
        # extend it
        ldpath = filter(None, [sharedhome] + reqldpath + ldpath)
        # trim it and set it
        env['LD_LIBRARY_PATH'] = os.pathsep.join(uniq(ldpath))

        # adjust the external include path
        inchome = list(os.environ.get('MM_INCLUDES', '').split())
        # we deposit header files here
        prodinc = os.path.join(self.prefix, 'include')
        # extend it
        inchome = filter(None, [prodinc] + inchome)
        # trim it and set it
        env['MM_INCLUDES'] = ' '.join(inchome)

        # adjust the external include path
        libhome = list(os.environ.get('MM_LIBPATH', '').split())
        # we deposit libraries here
        prodlib = os.path.join(self.prefix, 'lib')
        # extend it
        libhome = filter(None, [prodlib] + libhome)
        # trim it and set it
        env['MM_LIBPATH'] = ' '.join(libhome)

        # print it out
        what = self.show
        if what is True:
            print("env:")
            for name in sorted(env.keys()):
                print('  {} = {!r}'.format(name, env[name]))
        else:
            # try to
            try:
                # print {what} i was asked to show
                print(env[what])
            # if i don't recognize it
            except KeyError:
                # no worries
                pass

        # update the actual environment
        os.environ.update(env)
        # remove CDPATH: it's broken on older versions of /bin/sh
        if os.environ.get('CDPATH'): del os.environ['CDPATH']

        # all done
        return env


    def buildCommand(self):
        """
        Construct the {make} command line
        """
        # get the argument list from the {make} wrapper
        argv = self.make.argv
        # place the current directory on the path
        argv.append('-I')
        argv.append(os.path.curdir)
        # place the project {.mm} directory on the path
        argv.append('-I')
        argv.append(os.path.join(self.project.root, self.project.marker))
        # place the user's {.mm} directory on the path
        if self.user.mm:
            argv.append('-I')
            argv.append(self.user.mm)
        # add the include directives to the command line
        for directory in self.includes:
            argv.append('-I')
            argv.append(os.path.join(self.home, directory))
        # add the standard makefile
        argv.append('-f')
        argv.append(os.path.join(self.home, 'make', 'std-make.def'))
        # and the extra arguments harvested from the command line; skip {args[0]}
        argv.extend(self.options.args[1:])
        # all done
        return


    def execute(self):
        """
        Invoke {make}
        """
        # if i am only setting up the environment
        # for {sh} based shells
        if self.exportPaths == 'sh':
            print('export {}="{}"'.format('PATH', self.environ['PATH']))
            print('export {}="{}"'.format('LD_LIBRARY_PATH', self.environ['LD_LIBRARY_PATH']))
            print('export {}="{}"'.format('PYTHONPATH', self.environ['PYTHONPATH']))
            print('export {}="{}"'.format('MM_INCLUDES', self.environ['MM_INCLUDES']))
            print('export {}="{}"'.format('MM_LIBPATH', self.environ['MM_LIBPATH']))
            return 0
        # for {csh} based shells
        if self.exportPaths == 'csh':
            print('setenv {} "{}"'.format('PATH', self.environ['PATH']))
            print('setenv {} "{}"'.format('LD_LIBRARY_PATH', self.environ['LD_LIBRARY_PATH']))
            print('setenv {} "{}"'.format('PYTHONPATH', self.environ['PYTHONPATH']))
            print('setenv {} "{}"'.format('MM_INCLUDES', self.environ['MM_INCLUDES']))
            print('setenv {} "{}"'.format('MM_LIBPATH', self.environ['MM_LIBPATH']))
            return 0
        # if i am only printing the environment
        if self.envonly == 'sh':
            for name, value in self.environ.items():
                print('export {}="{}"'.format(name, value))
            return 0
        if self.envonly == 'csh':
            for name, value in self.environ.items():
                print('setenv {} "{}"'.format(name, value))
            return 0
        # if i am showing the user what is being done
        if self.show and not self.quiet:
            print("executing:")
            print("  {}".format(self.make.command))
        # if this is a dry run
        if self.dry:
            # and we are not supposed be quiet
            if not self.quiet:
                # say so
                complain(msg='info: dry run')
            # and return
            return 0

        # go to the correct directory
        if self.directory: os.chdir(self.directory)

        # create the necessary directories
        self.createDirectories()

        # set up the subprocess settings
        settings = {
            'args': self.make.argv,
            'executable': self.make.gnumake,
            'universal_newlines': True,
            'shell': False
            }
        # invoke
        with subprocess.Popen(**settings) as child:
            # wait for it to finish
            status = child.wait()
        # and return its status
        return status


    # interface
    def run(self):
        # build the command line
        self.buildCommand()
        # prime the environment
        self.environ = self.setEnvironment()
        # execute it
        status = self.execute()
        # return the status code
        return status


    # meta methods
    def __init__(self):
        self.envonly = self.options.get('env', False)
        # check for dry run
        self.dry = self.options.get('dry', False)
        # check for show and tell
        self.show = self.options.get('show', False)
        # check for gag orders
        self.quiet = self.options.get('quiet', False)
        # check whether the user wants to us to set up the runtime environment
        self.exportPaths = self.options.get('paths', False)
        # verify that the platform is supported
        if not os.path.exists(os.path.join(self.home, 'target', self.build.machine)):
            # complain
            msg = 'error: platform {!r} is not supported by config'.format(self.build.machine)
            complain(msg)

        # verify that the user selected targets are understood
        for target in self.build.user:
            # if the corresponding target file does not exist
            if not os.path.exists(os.path.join(self.home, 'target', target)):
                # complain
                complain(msg='error: target {!r} is not supported by config'.format(target))

        # adjust {makefile}
        self.directory, self.makefile = self.getLocalMakefile()
        # set up the build directory
        self.bldroot = os.path.abspath(os.path.expanduser(self.getBuildRoot()))
        # set up the installation directory
        self.prefix = os.path.abspath(os.path.expanduser(self.getExportRoot()))
        # read the requirements
        self.requirements = self.getProjectRequirements()
        # load the project options
        self.loadProjectOptions()
        # load the platform options
        self.loadPlatformOptions()
        # load the host options
        self.loadHostOptions()
        # load the developer options
        self.loadDeveloperOptions()

        # and return
        return


    def _loadSymbols(self, path, context=None):
        """
        Load symbols from the python source file {path}
        """
        # try
        try:
            # to open the file
            stream = open(path, "r")
        # if it's not there
        except IOError:
            # we are done
            return {}
        # initialize the symbol repository
        symbols = {} if context is None else context
        # load the symbols
        exec(stream.read(), symbols)
        # and return them
        return symbols

    def _decorate(self, optfile, category):
        """
        Give a compliant method in an {optfile} an opportunity to tune my build options
        """
        # load the symbols
        symbols = self._loadSymbols(path=optfile)
        # attempt to
        try:
            # get the build decorator
            decorate = symbols[category]
        # if it failed
        except KeyError:
            # no recovery possible
            return
        # if it succeeded, have it decorate me
        return decorate(self)


# the main entry point
def run():
    """
    Replacement for the bash based {mm} script
    """
    # instantiate a builder
    builder = Builder()

    # start printing diagnostics
    if builder.show and not builder.quiet:
        print('state:')
        print('  verbose:', builder.show)
        print('  dry run:', builder.dry)
        print('  config:')
        print('    mm:', builder.mm)
        print('    home:', builder.home)
        print('    local makefile:', builder.makefile)
        print('    includes', builder.includes)
        print('  make:')
        print('    tool:', builder.make.gnumake)
        print('  host:')
        print('    name:', builder.host.name)
        print('    system:', builder.host.system)
        print('    release:', builder.host.release)
        print('    architecture:', builder.host.architecture)
        print('  user:')
        print('    name:', builder.user.name)
        print('    home:', builder.user.home)
        print('  project:')
        print('    name:', builder.project.name)
        print('    root:', builder.project.root)
        print('  targets:')
        print('    user:', builder.build.user)
        print('    machine:', builder.build.machine)
        print('  products:')
        print('    intermediate files:', builder.bldroot)
        print('    installation files:', builder.prefix)
        print('  external requirements:')
        for requirement in builder.requirements:
            print('    {}'.format(requirement))

    # run
    return builder.run()


# main
if __name__ == '__main__':
    # invoke the main routine
    status = run()
    # and exit
    sys.exit(status)


# end of file
