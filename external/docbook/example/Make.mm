#-*- Makefile -*-
#
# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#
#                               Michael A.G. Aivazis
#                        California Institute of Technology
#                        (C) 1998-2004  All Rights Reserved
#
# <LicenseText>
#
# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#

PROJECT = docbook_example
PACKAGE = example


PROJ_TIDY += *.log  tex-math-equations.*

# directory structure

BUILD_DIRS = \

OTHER_DIRS = \


RECURSE_DIRS = $(BUILD_DIRS) $(OTHER_DIRS)

#--------------------------------------------------------------------------
#

all: 
	BLD_ACTION="all" $(MM) recurse

distclean::
	BLD_ACTION="distclean" $(MM) recurse

clean::
	BLD_ACTION="clean" $(MM) recurse

tidy:: tidy-tmpxml tidy-tmpxsl
	BLD_ACTION="tidy" $(MM) recurse

export::
	BLD_ACTION="export" $(MM) recurse

test::
	BLD_ACTION="test" $(MM) recurse



DOCBOOKSOURCETEMPLATES = \
	Introduction.txml \


include docbook/default.def


docs: export-docbook-docs

# version
# $Id: Make.mm,v 1.1 2009/04/06 17:28:26 linjiao Exp $

# End of file
