#--------------------------------------------------------------------------
#
#                       Michael A.G. Aivazis
#                California Institute of Technology
#                   (C) 1999 All Rights Reserved
#
#--------------------------------------------------------------------------

#
# $Log: Make.mm,v $
# Revision 1.1  1999/11/17 00:22:39  aivazis
# Original source
#

PROJECT = LogAnalyzer
SUBPACKAGES = FileScanners Notify

EXPORT_SCRIPTDIR := $(EXPORT_SCRIPTDIR)/$(PROJECT)
EXPORT_PYTHON_MODULES = \
    __init__.py \
    test.py \
    owners.inp

export:: export-python-modules
	BLD_ACTION="export" RECURSE_DIRS="$(SUBPACKAGES)" \
        EXPORT_SCRIPTDIR="$(EXPORT_SCRIPTDIR)" $(MM) recurse 


#
# End of file
