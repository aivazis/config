# -*- Makefile -*-
#
# michael a.g. aïvázis
# orthologue
# (c) 1998-2018 all rights reserved
#


PROJECT = config
PACKAGE = apache


WWW_SERVER=root@orthologue.com

all: tidy

deploy:
	ssh $(WWW_SERVER) 'service apache2 restart'


# end of file 
