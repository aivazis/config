# The following dictionary will be used to convert docbook
# xml templates (*.txml)
# to docbook xml source. All keys are map to values.
# There are now two files: web_absolutepath and web_relativepath
# web_absolutepath is for pdf format product. Because pdf cannot contain movies and some other medias, we have to used absolute web links
# web_relativepath is for html tar ball producet. It can contain everything that is documentation in one tar ball, so in most cases relative link is sufficient. Certainly there still are cases where you want to put up absolute links, for example those links to download binary installers, which should not be included in the documentation tar ball..

urldict = {
    'xxxWEBSITExxx': "http://arcscluster.caltech.edu",
    }
