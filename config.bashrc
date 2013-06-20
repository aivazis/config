# 
#--------------------------------------------------------------------------
#                       Julian C. Cummings
#                California Institute of Technology
#                   (C) 2003 All Rights Reserved
#
#--------------------------------------------------------------------------
#

# This is a sample .bashrc file for setting up your user environment
# under bash to use the VTF build procedure.  Users can customize this
# file to reflect their local machine environment and indicate the 
# installed location of various optional software packages used by the 
# VTF.  Users should then source this file before using the build procedure.

#
# Generic tools installation directory for 3rd party software
#
  export TOOLS_DIR=/home/tools            # local install directory
  export TOOLS_INCDIR=$TOOLS_DIR/include
  export TOOLS_LIBDIR=$TOOLS_DIR/lib

# Add tools directory to PATH variables
  if [ "$PATH" = "" ] 
  then
    export PATH=$TOOLS_DIR/bin
  else
    export PATH=$TOOLS_DIR/bin:$PATH
  fi
  if [ "$LD_LIBRARY_PATH" = "" ] 
  then
    export LD_LIBRARY_PATH=$TOOLS_DIR/lib
  else
    export LD_LIBRARY_PATH=$TOOLS_DIR/lib:$LD_LIBRARY_PATH
  fi
  if [ "$MANPATH" = "" ] 
  then
    export MANPATH=$TOOLS_DIR/man
  else
    export MANPATH=$TOOLS_DIR/man:$MANPATH
  fi

#
# Basic build procedure settings
#
  export DEVELOPER=$USER                 # VTF developer name            
  export BLD_ROOT=$HOME/build            # root directory of VTF builds
  export EXPORT_ROOT=$HOME/products      # root directory of VTF build products
  export BLD_CONFIG=$BLD_ROOT/config     # location of build procedure files
  export TARGET=debug,mpi                # VTF build target options
  export VTF_DIR=$HOME/vtf               # VTF install directory
  # export GNU_MAKE=gmake                # name of GNU make command

# Add build procedure and VTF products directories to PATH variables
  export PATH=$BLD_CONFIG/make:$PATH:$EXPORT_ROOT/bin
  export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$EXPORT_ROOT/lib

#
# CVS setup
#
  export CVS_RSH=ssh
  export CVSROOT=cvs.cacr.caltech.edu:/home/proj/vtf3d   # VTF repository home

#
# Optional compilers (uncomment as needed)
#

# Absoft Pro FORTRAN compiler
  # export TARGET_F77=Absoft
  # export ABSOFT=$TOOLS_DIR/ProFortran-8.0  # Absoft installation directory
  # export ABSOFT_DIR=$ABSOFT
  # export ABSOFT_LIBDIR=$ABSOFT/lib
  # export PATH=$ABSOFT/bin:$PATH

# Portland Group compilers
  # export TARGET_F77=PGI-3.0
  # export TARGET_CC=PGI-3.0
  # export TARGET_CXX=PGI-3.0
  # export PGI_DIR=/usr/pgi                  # PGI installation directory
  # export PGI_LIBDIR=$PGI_DIR/linux86/lib_rh6
  # export LM_LICENSE_FILE=$PGI_DIR/license.dat
  # export PATH=$PGI_DIR/linux86/bin:$PATH
  # export MANPATH=$PGI_DIR/man:$MANPATH

# KAI C++ Compiler
  # export TARGET_CXX=KAI-4.0
  # export KAI_DIR=/usr/local/KAI            # KCC installation directory
  # export PATH=$KAI_DIR/bin:$PATH

# GCC 3.x Compiler
  # export TARGET_F77=gcc-3.0
  # export TARGET_CC=gcc-3.0
  # export TARGET_CXX=gcc-3.0
  # export GCC_DIR=/usr/local/gnu            # GCC installation directory
  # export PATH=$GCC_DIR/bin:$PATH
  # export LD_LIBRARY_PATH=$GCC_DIR/lib:$LD_LIBRARY_PATH

# Intel 8.0 beta Compiler
  # export TARGET_F77=Intel8beta
  # export TARGET_CC=Intel8beta
  # export TARGET_CXX=Intel8beta
  # export INTEL_DIR=/usr/local/intel-compilers   # Intel install directory
  # export PATH=$INTEL_DIR/bin:$PATH
  # export LD_LIBRARY_PATH=$INTEL_DIR/lib:$LD_LIBRARY_PATH

#
# Python support
#
  export PYTHON_DIR=$TOOLS_DIR/python-2.2.2  # Python installation directory
  export PYTHON_VERSION=2.2
  export PYTHON_LIBDIR=$PYTHON_DIR/lib/python$PYTHON_VERSION
  export PYTHON_INCDIR=$PYTHON_DIR/include/python$PYTHON_VERSION
  export PYTHONPATH=$EXPORT_ROOT/modules

# Add Python to user's PATH if necessary.
  export PATH=$PYTHON_DIR/bin:$PATH

#
# MPI/mpich support
#
  export MPI_DIR=/usr/local/mpich            # MPI installation directory
  export MPI_INCDIR=$MPI_DIR/include
  export MPI_LIBDIR=$MPI_DIR/lib
  export MPI_VERSION=1.2.5

# Add MPI to PATH variables if installed in non-standard location.
  export PATH=$MPI_DIR/bin:$PATH
  export LD_LIBRARY_PATH=$MPI_DIR/lib:$LD_LIBRARY_PATH
  export MANPATH=$MPI_DIR/man:$MANPATH

#
# Optional external package settings (uncomment as needed)
#

# Pyre scripting environment
  # export PYTHIA_DIR=$HOME/pythia-0.2         # Pythia installation directory

# ACIS solid geometry package
  # export ACIS_DIR=$TOOLS_DIR/acis-7.0        # Acis installation directory
  # export ACIS_INCDIR=$ACIS_DIR
  # export ACIS_LIBDIR=$ACIS_DIR/lib/linux_so
# Add Acis to PATH variables.
  # export PATH=$PATH:$ACIS_DIR/bin/linux
  # export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$ACIS_LIBDIR

# TECPLOT plotting package
  # export TECPLOT_DIR=$TOOLS_DIR/tecplot-9.0  # Tecplot installation directory
  # export TECPLOT_INCDIR=$TECPLOT_DIR/include
  # export TECPLOT_LIBDIR=$TECPLOT_DIR/lib
  # export TEC90HOME=$TECPLOT_DIR
  # export TLMHOST=@asap.cacr.caltech.edu
# Add Tecplot to user's PATH.
  # export PATH=$PATH:$TECPLOT_DIR/bin

# Insure
  # export PARASOFT_DIR=$TOOLS_DIR/parasoft    # Parasoft install directory
  # export PATH=$PARASOFT_DIR/bin.linux2:$PATH
  # export LD_LIBRARY_PATH=$PARASOFT_DIR/lib.linux2:$LD_LIBRARY_PATH

# Tau profiling tool
  # export TAUROOTDIR=$TOOLS_DIR/Tau           # Tau installation directory
  # export TARGET=$TARGET,tau
# Add Tau and Java to user's PATH.
  # export PATH=$TAUROOTDIR/i386_linux/bin:/usr/local/j2sdk_nb/j2sdk1.4.2/bin:$PATH

# Blitz C++ array library
  # export BLITZ_DIR=$TOOLS_DIR/Blitz++        # Blitz installation directory

# Zoltan decomposition and partitioning package
  # export ZOLTAN_DIR=$TOOLS_DIR/zoltan        # Zoltan installation directory

# Xdmf I/O package
  # export XDMF_DIR=$TOOLS_DIR/Xdmf            # Xdmf installation directory
# Add Xdmf to PATH variables
  # export PYTHONPATH=$PYTHONPATH:$XDMF_DIR/lib
  # export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$XDMF_DIR/lib

# HDF5 I/O package
  # export HDF5_DIR=$TOOLS_DIR/hdf5-1.4.5      # HDF5 installation directory
# Add HDF5 to PATH variables
  # export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$HDF5_DIR/lib

# HDF4 I/O package
  # export HDF4_DIR=$TOOLS_DIR/HDF4.1r2        # HDF4 installation directory

# Visual3 plotting package
  # export VISUAL3_DIR=$TOOLS_DIR/visual3      # Visual3 installation directory

# Matlab package
  # export MATLAB_DIR=$TOOLS_DIR/matlab        # Matlab install directories
  # export MATLAB_INCDIR=$MATLAB_DIR/include
  # export MATLAB_LIBDIR=$MATLAB_DIR/lib

# Add Matlab to PATH variables if installed in non-standard location.
  # export PATH=$PATH:$MATLAB_DIR/bin
  # export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$MATLAB_LIBDIR

# Put AMROC Matlab scripts into path
  # export MATLABPATH=$VTF_DIR/amroc/matlab


# version
# $Id: config.bashrc,v 1.10 2004/04/28 02:11:01 cummings Exp $

#
# End of file
