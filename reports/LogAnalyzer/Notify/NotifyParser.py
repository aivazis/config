#!/bin/env python
#
#--------------------------------------------------------------------------
#
#                       Michael A.G. Aivazis
#                California Institute of Technology
#                   (C) 1999 All Rights Reserved
#
#--------------------------------------------------------------------------

# $Log: NotifyParser.py,v $
# Revision 1.2  1999/11/17 05:10:23  aivazis
# Removed debugging verbiage
#
# Revision 1.1  1999/11/17 00:22:39  aivazis
# Original source
#

from TrivialParser import TrivialParser
from NotifyScanner import NotifyScanner
from ListParser import ListParser

from LogAnalyzer.FileScanners.Tokenizer import Tokenizer, EndOfFile

class NotifyParser(TrivialParser):

    def consolidateNotificationTable(self):

        table = {}

        for module in self._modules.keys():
            recipients = self._modules[module]
            while recipients:
                recipient = recipients[0]
                recipients = recipients[1:]

                # if recipient is a key in the table
                # it is a fully expanded email address and we are done
                if table.has_key(recipient):
                    table[recipient].append(module)
                    continue

                # otherwise check the alias list for a possible match
                if self._aliases.has_key(recipient):
                    recipients = self._aliases[recipient] + recipients
                    continue

                # no alias, must be an email address
                table[recipient] = [ module ]

        return table
    

    # The main parsing loop

    def parse(self):
        try:
            while 1:
                token = self._tokenizer.fetch(self._scanner)
                token.identify(self)

        except EndOfFile:
            pass

        return

    # Handlers

    def aName(self, token):
        self._tokenizer.unfetch(token)
        self._names = self._getNameList()
        return


    def anAliasDelimiter(self, token):
        if not self._names:
            name = self._tokenizer.name
            line = self._tokenizer.line
            column = self._tokenizer.column
            raise MisplacedDelimiter(name, line, column, token.lexeme)

        if len(self._names) > 1:
            name = self._tokenizer.name
            line = self._tokenizer.line
            column = self._tokenizer.column
            raise MisplacedDelimiter(name, line, column, token.lexeme)

        value = self._getNameList()

        for alias in self._names:
            if self._aliases.has_key(alias):
                self._aliases[alias] = self._aliases[alias] + value
            else:
                self._aliases[alias] = value
        
        return


    def anActionDelimiter(self, token):
        if not self._names:
            name = self._tokenizer.name
            line = self._tokenizer.line
            column = self._tokenizer.column
            raise MisplacedDelimiter(name, line, column, token.lexeme)

        modules = self._names
        owners = self._getNameList()

        for module in modules:
            if self._modules.has_key(module):
                self._modules[module] = self._modules[module] + owners
            else:
                self._modules[module] = owners

        return


    def anEndOfRecord(self, token):
        return

    #
    # Other methods
    #

    def __init__(self, file):
        self._tokenizer = Tokenizer(file)
        self._scanner = NotifyScanner()
        self._listParser = ListParser()

        self._aliases = {}
        self._modules = {}

        self._lhs = []
        self._names = []

        return

    
    def _getNameList(self):
        return self._listParser.parse(self._tokenizer, self._scanner)


    def _dump(self):
        
        print "Known aliases:"
        for alias in self._aliases.keys():
            print "    %s -> %s" % (alias, self._aliases[alias])

        print "Module notification list:"
        for module in self._modules.keys():
            print "    %s -> %s" % (module, self._modules[module])

        return

#
# Exceptions
#

class MisplacedDelimiter(Exception):

    def __init__(self, file, line, column, delimiter):
        self.file = file
        self.line = line
        self.column = column
        self.delimiter = delimiter
        return


    def __str__(self):
        str = "Syntax error in '%s', line %d, column %d:" % (self.file, self.line, self.column)
        str = str + " No lhs. Expected: [list of names] %s [list of values]" % self.delimiter
        return str

#
# Test
#
if __name__ == "__main__":

    file = open("owners.inp", "r")
    parser = NotifyParser(file)
    parser.parse()
    parser._dump()
    

#
# End of file
