# 
#--------------------------------------------------------------------------
#                       Julian C. Cummings
#                California Institute of Technology
#                   (C) 2003 All Rights Reserved
#
#--------------------------------------------------------------------------
#

# This is a sample .cshrc file for setting up your user environment
# under c-shell to use the VTF build procedure.  Users can customize this
# file to reflect their local machine environment and indicate the 
# installed location of various optional software packages used by the 
# VTF.  Users should then source this file before using the build procedure.

#
# Generic tools installation directory for 3rd party software
#
  setenv TOOLS_DIR /home/tools            # local install directory
  setenv TOOLS_INCDIR $TOOLS_DIR/include
  setenv TOOLS_LIBDIR $TOOLS_DIR/lib

# Add tools directory to PATH variables
  if !($?PATH) then
    setenv PATH $TOOLS_DIR/bin
  else
    setenv PATH $TOOLS_DIR/bin:${PATH}
  endif
  if !($?LD_LIBRARY_PATH) then
    setenv LD_LIBRARY_PATH $TOOLS_DIR/lib
  else
    setenv LD_LIBRARY_PATH $TOOLS_DIR/lib:${LD_LIBRARY_PATH}
  endif
  if !($?MANPATH) then
    setenv MANPATH $TOOLS_DIR/man
  else
    setenv MANPATH $TOOLS_DIR/man:${MANPATH}
  endif

#
# Basic build procedure settings
#
  setenv DEVELOPER $USER                 # VTF developer name            
  setenv BLD_ROOT $HOME/build            # root directory of VTF builds
  setenv EXPORT_ROOT $HOME/products      # root directory of VTF build products
  setenv BLD_CONFIG $BLD_ROOT/config     # location of build procedure files
  setenv TARGET debug,mpi                # VTF build target options
  setenv VTF_DIR $HOME/vtf               # VTF install directory
  # setenv GNU_MAKE gmake                # name of GNU make command

# Add build procedure and VTF products directories to PATH variables
  setenv PATH $BLD_CONFIG/make:${PATH}:$EXPORT_ROOT/bin
  setenv LD_LIBRARY_PATH ${LD_LIBRARY_PATH}:$EXPORT_ROOT/lib

#
# CVS setup
#
  setenv CVS_RSH ssh
  setenv CVSROOT cvs.cacr.caltech.edu:/home/proj/vtf3d   # VTF repository home

#
# Optional compilers (uncomment as needed)
#

# Absoft Pro FORTRAN compiler
  # setenv TARGET_F77 Absoft
  # setenv ABSOFT $TOOLS_DIR/ProFortran-8.0  # Absoft installation directory
  # setenv ABSOFT_DIR $ABSOFT
  # setenv ABSOFT_LIBDIR $ABSOFT/lib
  # setenv PATH $ABSOFT/bin:${PATH}

# Portland Group compilers
  # setenv TARGET_F77 PGI-3.0
  # setenv TARGET_CC PGI-3.0
  # setenv TARGET_CXX PGI-3.0
  # setenv PGI_DIR /usr/pgi                  # PGI installation directory
  # setenv PGI_LIBDIR $PGI_DIR/linux86/lib_rh6
  # setenv LM_LICENSE_FILE $PGI_DIR/license.dat
  # setenv PATH $PGI_DIR/linux86/bin:${PATH}
  # setenv MANPATH $PGI_DIR/man:${MANPATH}

# KAI C++ Compiler
  # setenv TARGET_CXX KAI-4.0
  # setenv KAI_DIR /usr/local/KAI            # KCC installation directory
  # setenv PATH $KAI_DIR/bin:${PATH}

# GCC 3.x Compiler
  # setenv TARGET_F77 gcc-3.0
  # setenv TARGET_CC gcc-3.0
  # setenv TARGET_CXX gcc-3.0
  # setenv GCC_DIR /usr/local/gnu            # GCC installation directory
  # setenv PATH $GCC_DIR/bin:${PATH}
  # setenv LD_LIBRARY_PATH $GCC_DIR/lib:${LD_LIBRARY_PATH}

# Intel 8.0 beta Compiler
  # setenv TARGET_F77 Intel8beta
  # setenv TARGET_CC Intel8beta
  # setenv TARGET_CXX Intel8beta
  # setenv INTEL_DIR /usr/local/intel-compilers   # Intel install directory
  # setenv PATH $INTEL_DIR/bin:${PATH}
  # setenv LD_LIBRARY_PATH $INTEL_DIR/lib:${LD_LIBRARY_PATH}

#
# Python support
#
  setenv PYTHON_DIR $TOOLS_DIR/python-2.2.2  # Python installation directory
  setenv PYTHON_VERSION 2.2
  setenv PYTHON_LIBDIR $PYTHON_DIR/lib/python$PYTHON_VERSION
  setenv PYTHON_INCDIR $PYTHON_DIR/include/python$PYTHON_VERSION
  setenv PYTHONPATH $EXPORT_ROOT/modules

# Add Python to user's PATH if necessary.
  setenv PATH $PYTHON_DIR/bin:${PATH}

#
# MPI/mpich support
#
  setenv MPI_DIR /usr/local/mpich            # MPI installation directory
  setenv MPI_INCDIR $MPI_DIR/include
  setenv MPI_LIBDIR $MPI_DIR/lib
  setenv MPI_VERSION 1.2.5

# Add MPI to PATH variables if installed in non-standard location.
  setenv PATH $MPI_DIR/bin:${PATH}
  setenv LD_LIBRARY_PATH $MPI_DIR/lib:${LD_LIBRARY_PATH}
  setenv MANPATH $MPI_DIR/man:${MANPATH}

#
# Optional external package settings (uncomment as needed)
#

# Pyre scripting environment
  # setenv PYTHIA_DIR $HOME/pythia-0.2         # Pythia installation directory

# ACIS solid geometry package
  # setenv ACIS_DIR $TOOLS_DIR/acis-7.0        # Acis installation directory
  # setenv ACIS_INCDIR $ACIS_DIR
  # setenv ACIS_LIBDIR $ACIS_DIR/lib/linux_so
# Add Acis to PATH variables.
  # setenv PATH ${PATH}:$ACIS_DIR/bin/linux
  # setenv LD_LIBRARY_PATH ${LD_LIBRARY_PATH}:${ACIS_LIBDIR}

# TECPLOT plotting package
  # setenv TECPLOT_DIR $TOOLS_DIR/tecplot-9.0  # Tecplot installation directory
  # setenv TECPLOT_INCDIR $TECPLOT_DIR/include
  # setenv TECPLOT_LIBDIR $TECPLOT_DIR/lib
  # setenv TEC90HOME $TECPLOT_DIR
  # setenv TLMHOST @asap.cacr.caltech.edu
# Add Tecplot to user's PATH.
  # setenv PATH ${PATH}:$TECPLOT_DIR/bin

# Insure
  # setenv PARASOFT_DIR $TOOLS_DIR/parasoft    # Parasoft install directory
  # setenv PATH $PARASOFT_DIR/bin.linux2:${PATH}
  # setenv LD_LIBRARY_PATH $PARASOFT_DIR/lib.linux2:${LD_LIBRARY_PATH}

# Tau profiling tool
  # setenv TAUROOTDIR $TOOLS_DIR/Tau           # Tau installation directory
  # setenv TARGET ${TARGET},tau
# Add Tau and Java to user's PATH.
  # setenv PATH $TAUROOTDIR/i386_linux/bin:/usr/local/j2sdk_nb/j2sdk1.4.2/bin:${PATH}

# Blitz C++ array library
  # setenv BLITZ_DIR $TOOLS_DIR/Blitz++        # Blitz installation directory

# Zoltan decomposition and partitioning package
  # setenv ZOLTAN_DIR $TOOLS_DIR/zoltan        # Zoltan installation directory

# Xdmf I/O package
  # setenv XDMF_DIR $TOOLS_DIR/Xdmf            # Xdmf installation directory
# Add Xdmf to PATH variables
  # setenv PYTHONPATH ${PYTHONPATH}:$XDMF_DIR/lib
  # setenv LD_LIBRARY_PATH ${LD_LIBRARY_PATH}:$XDMF_DIR/lib

# HDF5 I/O package
  # setenv HDF5_DIR $TOOLS_DIR/hdf5-1.4.5      # HDF5 installation directory
# Add HDF5 to PATH variables
  # setenv LD_LIBRARY_PATH ${LD_LIBRARY_PATH}:$HDF5_DIR/lib

# HDF4 I/O package
  # setenv HDF4_DIR $TOOLS_DIR/HDF4.1r2        # HDF4 installation directory

# Visual3 plotting package
  # setenv VISUAL3_DIR $TOOLS_DIR/visual3      # Visual3 installation directory

# Matlab package
  # setenv MATLAB_DIR $TOOLS_DIR/matlab        # Matlab install directories
  # setenv MATLAB_INCDIR $MATLAB_DIR/include
  # setenv MATLAB_LIBDIR $MATLAB_DIR/lib

# Add Matlab to PATH variables if installed in non-standard location.
  # setenv PATH ${PATH}:$MATLAB_DIR/bin
  # setenv LD_LIBRARY_PATH ${LD_LIBRARY_PATH}:${MATLAB_LIBDIR}

# Put AMROC Matlab scripts into path
  # setenv MATLABPATH $VTF_DIR/amroc/matlab


# version
# $Id: config.cshrc,v 1.9 2004/04/28 02:08:07 cummings Exp $

#
# End of file
