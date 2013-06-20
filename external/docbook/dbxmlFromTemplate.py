#!/usr/bin/env python


'''
dbxmlFromTemplate.py Introduction.txml relativepath.py

#relativepath.py
xxxWEBSITExxx = "http://arcscluster.caltech.edu"
'''



import os, sys


def convert( txml, urldict ):
    '''create xml source from template xml

    This function search for any key in urldict.keys()
    in the template text, and replace them with
    the corresponding value. The converted texts are
    saved to a new xml file.
    '''
    root, ext = os.path.splitext( txml )
    xml = root + ".xml"

    text = open(txml).read()
    for k,v in urldict.iteritems():
        text = text.replace( k, v )
        continue

    open( xml, 'w' ).write( text )
    return


def main():
    xml = sys.argv[1]
    modname = sys.argv[2]
    if '.' not in sys.path: sys.path = ['.'] + sys.path
    module = __import__( modname )
    urldict = module.urldict
    convert( xml, urldict )
    return


if __name__ == "__main__": main()

