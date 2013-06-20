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

import Notify

def testNotificationTable():
    configurationFile = open("owners.inp", "r")
    table = Notify.createTable(configurationFile)

    print table

    return

#
# Main
#
if __name__ == "__main__":
    testNotificationTable()


#
# End of file
