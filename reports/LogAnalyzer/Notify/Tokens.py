#!/bin/env python
#
#--------------------------------------------------------------------------
#
#                       Michael A.G. Aivazis
#                California Institute of Technology
#                   (C) 1999 All Rights Reserved
#
#--------------------------------------------------------------------------

# $Log: Tokens.py,v $
# Revision 1.1  1999/11/17 00:22:39  aivazis
# Original source
#

from LogAnalyzer.FileScanners.Token import Token

#
# The token classes
#

class Whitespace(Token):
    #regExp = r"\s+"
    regExp = r"[ \t]+"

    def identify(self, auth): return auth.aWhitespace(self)
    def __str__(self): return "{whitespace}"


class Comments(Token):
    regExp = r"[!;#].*\n$"

    def identify(self, auth): return auth.aComment(self)
    def __str__(self): return "{comment}"
    

class Continuation(Token):
    regExp = r"\\\n"

    def identify(self, auth): auth.aContinuationMarker(self)
    def __str__(self): return "{continuation}"


class EndOfRecord(Token):
    regExp = r"\n"

    def identify(self, auth): auth.anEndOfRecord(self)
    def __str__(self): return "{end of record}"


class ActionDelimiter(Token):
    regExp = r":"

    def identify(self, auth): auth.anActionDelimiter(self)
    def __str__(self): return "{action separator}"


class AliasDelimiter(Token):
    regExp = r"="

    def identify(self, auth): auth.anAliasDelimiter(self)
    def __str__(self): return "{alias separator}"


class ItemDelimiter(Token):
    regExp = r","

    def identify(self, auth): auth.anItemDelimiter(self)
    def __str__(self): return "{item separator}"


class Name(Token):
    regExp = r"<[Aa][Ll][Ll]>|<[Uu][Nn][Kk][Nn][Oo][Ww][Nn]>|[a-zA-Z_][a-zA-Z0-9_@.+-]*"

    def identify(self, auth): auth.aName(self)
    def __str__(self): return "{name: " + self.lexeme + "}"



#
# End of file
