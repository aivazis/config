#!/bin/env python
#
#--------------------------------------------------------------------------
#
#                       Michael A.G. Aivazis
#                California Institute of Technology
#                   (C) 1999 All Rights Reserved
#
#--------------------------------------------------------------------------

# $Log: TrivialParser.py,v $
# Revision 1.1  1999/11/17 00:22:39  aivazis
# Original source
#

class TrivialParser:

    # The boring tokens

    def aComment(self, token): return
    def aWhitespace(self, token): return
    def aContinuationMarker(self, token): return

    # The delimiters

    def anEndOfRecord(self, token): raise UnhandledToken(self, token)
    def anActionDelimiter(self, token): raise UnhandledToken(self, token)
    def anAliasDelimiter(self, token): raise UnhandledToken(self, token)
    def anItemDelimiter(self, token): raise UnhandledToken(self, token)

    # The data

    def aName(self, token): raise UnhandledToken(parser, self, token)

#
# Exceptions
#
class UnhandledToken(Exception):

    def __init__(self, state, token):
        self.state = state
        self.token = token
        return

    def __str__(self):
        return "line %d, column %d: unexpected token %s" \
               % (self.token.line, self.token.column, self.token)

#
# End of file
