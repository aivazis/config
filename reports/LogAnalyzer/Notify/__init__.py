#!/bin/env python
#
#--------------------------------------------------------------------------
#
#                       Michael A.G. Aivazis
#                California Institute of Technology
#                   (C) 1999 All Rights Reserved
#
#--------------------------------------------------------------------------
#

# $Log: __init__.py,v $
# Revision 1.2  1999/11/17 00:43:12  aivazis
# Added Log header
#

from NotifyParser import NotifyParser

def createTable(file):
    parser = NotifyParser(file)
    parser.parse()

    table = parser.consolidateNotificationTable()
    return table


#
# End of file
