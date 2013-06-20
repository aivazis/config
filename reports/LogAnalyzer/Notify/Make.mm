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

PACKAGE = Notify

override EXPORT_SCRIPTDIR := $(EXPORT_SCRIPTDIR)/$(PACKAGE)
EXPORT_PYTHON_MODULES = \
    __init__.py \
    DebugParser.py \
    ListParser.py \
    NotifyParser.py \
    NotifyScanner.py \
    Tokens.py \
    TrivialParser.py 

export:: export-python-modules


#
# End of file
