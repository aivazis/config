#!/bin/env python
#
#--------------------------------------------------------------------------
#
#                       Michael A.G. Aivazis
#                California Institute of Technology
#                   (C) 1999 All Rights Reserved
#
#--------------------------------------------------------------------------

# $Log: Token.py,v $
# Revision 1.1  1999/11/17 00:22:39  aivazis
# Original source
#

class Token:

    def __init__(self, line, column, match):
        self.line = line
        self.column = column
        self.lexeme = match.group(0)
        self.size = len(self.lexeme)
        return

    def __str__(self):
        return "{token: %s}" % self.lexeme

#
# End of file
