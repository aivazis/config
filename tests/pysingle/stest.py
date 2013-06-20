#!/usr/bin/env python
# 
#  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# 
#                               Michael A.G. Aivazis
#                        (C) 1998-2001 All Rights Reserved
# 
#  <LicenseText>
# 
#  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# 

import pya, pyb

va = pya.get()
vb = pyb.get()

print "initial get: %d, %d -> %d" % (va, vb, va == vb)

pya.set(10)
va = pya.get()
vb = pyb.get()

print "after modification: %d, %d -> %d" % (va, vb, va == vb)

# version
__id__ = "$Id: stest.py,v 1.1 2001/09/08 18:23:41 aivazis Exp $"

#  End of file 
