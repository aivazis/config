#!/bin/env python
#
#--------------------------------------------------------------------------
#
#                       Michael A.G. Aivazis
#                California Institute of Technology
#                   (C) 1999 All Rights Reserved
#
#--------------------------------------------------------------------------

# $Log: Tokenizer.py,v $
# Revision 1.1  1999/11/17 00:22:39  aivazis
# Original source
#

import re
import string

class Tokenizer:

    """Convert an input stream into a stream of tokens"""

    def fetch(self, scanner):
        """Return a token from the input stream"""

        token = None
        if self._token:
            token = self._token
            self._token = None
        else:
            token = self._tokenize(scanner)

        return token


    def unfetch(self, token):
        """Put a token back into the token stream"""

        self._token = token
        return 


    def __init__(self, file):
        self.name = file.name                   # the name of the file we are processing
        self.text = ""                          # the line being processed
        self.line = 0                           # current line number
        self.column = 0                         # current offset into the line

        self._file = file                       # the open text stream
        self._token = None                      # the current token

        return

    #
    # Internal methods
    #

    def _tokenize(self, scanner):
        
        if self.column == len(self.text):
            text = self._newLine()

        # Attempt to get a token
        token = scanner.match(self.text, self.name, self.line, self.column)
        self.column = self.column + token.size
        return token


    def _newLine(self):

        self.column = 0
        while 1:
            text = self._file.readline()
            if not text: raise EndOfFile(self)

            self.line = self.line + 1
            if text:
                self.text = text
                return

        # unreachable
        return

#
# Exception classes
#

class EndOfFile(Exception):

    def __init__(self, scanner):
        self._name = scanner.name
        self._line = scanner.line
        return


    def __str__(self):
        return "End of file '%s' detected at line %d" % (self._name, self._line)

#
# End of file
