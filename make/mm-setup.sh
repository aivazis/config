#!/bin/sh
#
# michael a.g. aïvázis
# california institute of technology
# (c) 1998-2012 all rights reserved

# modify this to point to your location
alias mm='python3 ${HOME}/dv/config/make/mm.py'

# for convenience
alias mm.env='mm --env=sh'
alias mm.show='mm --show --dry'

# update the environment variables so code can run from its build location
mm.paths() {
    # the temp filename
    tmpfile=/tmp/mm-setup.sh
    # get {mm} to print out the path variables
    python3 ${HOME}/dv/config/make/mm.py --paths=sh $* > ${tmpfile}
    # source it
    source ${tmpfile}
    # and remove the temporary
    # rm ${tmpfile}
}

# end of file
