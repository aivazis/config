#!/bin/env python
#
#--------------------------------------------------------------------------
#
#                       Michael A.G. Aivazis
#                California Institute of Technology
#                   (C) 1999 All Rights Reserved
#
#--------------------------------------------------------------------------

# $Log: ListParser.py,v $
# Revision 1.1  1999/11/17 00:22:39  aivazis
# Original source
#

from NotifyScanner import NotifyScanner

from TrivialParser import TrivialParser

class ListParser(TrivialParser):

    #
    # The main parsing loop
    #
    def parse(self, tokenizer, scanner):
        self._reset(tokenizer, scanner)
        self._done = 0
        self._names = []
        while not self._done:
            token = self._tokenizer.fetch(self._scanner)
            token.identify(self)

        return self._names

    # The handlers

    def aName(self, token):
        self._names.append(token.lexeme)
        return

    def anItemDelimiter(self, token): return

    # The rest

    def anEndOfRecord(self, token): 
        self._fini(token)
        return

    def anActionDelimiter(self, token): 
        self._fini(token)
        return

    def anAliasDelimiter(self, token): 
        self._fini(token)
        return

    #
    # Other methods
    #

    def __init__(self):
        self._reset()
        return


    def _reset(self, tokenizer=None, scanner=None):
        self._done = 0
        self._names = []
        self._scanner = scanner
        self._tokenizer = tokenizer
        return



    def _fini(self, token):
        self._tokenizer.unfetch(token)
        self._done = 1
        return

#
# Test
#
if __name__ == "__main__":

    file = open("owners.inp", "r")
    parser = NotifyParser(file)
    parser.parse()
    

#
# End of file
