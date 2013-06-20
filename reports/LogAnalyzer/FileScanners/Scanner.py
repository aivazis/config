#!/bin/env python
#
#--------------------------------------------------------------------------
#
#                       Michael A.G. Aivazis
#                California Institute of Technology
#                   (C) 1999 All Rights Reserved
#
#--------------------------------------------------------------------------

# $Log: Scanner.py,v $
# Revision 1.1  1999/11/17 00:22:39  aivazis
# Original source
#

import re
import string

class Scanner:

    def match(self, text, filename, line, offset):

        match = self._scanner.match(text, offset)
        if not match: 
            raise TokenizationError(filename, line, offset, text)

        return self._decode(match, filename, line, offset)


    def __init__(self):
        self._scanner = self._constructTokenRecognizer()
        return


    def _constructTokenRecognizer(self):
        regexpList = map(self._constructRegExp, self.tokenClasses)
        regexp = string.join(regexpList, '|')
        return re.compile(regexp)


    def _constructRegExp(self, tokenClass):
        return "(?P<" + tokenClass.__name__ + ">" + tokenClass.regExp + ')'


    def _decode(self, match, filename, line, offset):
        i = 0
        for i in range(len(self.tokenClasses)):
            tokenClass = self.tokenClasses[i]
            if match.group(tokenClass.__name__):
                return tokenClass(line, offset, match)
            
        raise DecodingError(match, filename, line, offset)

#
# Exceptions
#

class TokenizationError(Exception):

    def __init__(self, filename, line, offset, text):
        self.filename = filename
        self.line = line
        self.offset = offset
        self.text = text

        return

    def __str__(self):
        str = "Error in '%s', line %d, column %d': could not match {%s}" \
              % (self.filename, self.line, self.offset, self.text)
        return str
                               
class DecodingError(Exception):

    def __init__(self, match, filename, line, offset):
        self.match = match
        self.filename = filename
        self.line = line
        self.offset = offset

        return

    def __str__(self):
        str = "Error in '%s', line %d, column %d': could not match {%s}" \
              % (self.filename, self.line, self.offset, self.match.group())
        return str
                               
#
# End of file
