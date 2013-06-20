#!/bin/env python
#
#--------------------------------------------------------------------------
#
#                       Michael A.G. Aivazis
#                California Institute of Technology
#                   (C) 1999 All Rights Reserved
#
#--------------------------------------------------------------------------

# $Log: NotifyScanner.py,v $
# Revision 1.1  1999/11/17 00:22:39  aivazis
# Original source
#

from LogAnalyzer.FileScanners.Scanner import Scanner

from Tokens import Name
from Tokens import ActionDelimiter, AliasDelimiter, ItemDelimiter
from Tokens import Whitespace, Comments, Continuation, EndOfRecord

#
# The lexer
#

class NotifyScanner(Scanner):

    tokenClasses = [
        EndOfRecord, 
        Whitespace, Comments, Continuation,
        ActionDelimiter, AliasDelimiter, ItemDelimiter, 
        Name
        ]
        
#
# End of file
