       --post-data=STRING    use the POST method; send STRING as the data.\n\
       --post-file=FILE      use the POST method; send contents of FILE.\n\
\n"), stdout);
#ifdef HAVE_SSL
  fputs (_("\
HTTPS (SSL) options:\n\
       --sslcertfile=FILE     optional client certificate.\n\
       --sslcertkey=KEYFILE   optional keyfile for this certificate.\n\
       --egd-file=FILE        file name of the EGD socket.\n\
       --sslcadir=DIR         dir where hash list of CA's are stured.\n\
       --sslcafile=FILE       file with bundle of CA's\n\
       --sslcerttype=0/1      Client-Cert type 0=PEM (default) / 1=ASN1 (DER)\n\
       --sslcheckcert=0/1     Check the server cert agenst given CA\n\
       --sslprotocol=0-3      choose SSL protocol; 0=automatic,\n\
                              1=SSLv2 2=SSLv3 3=TLSv1\n\
\n"), stdout);
#endif
  fputs (_("\
FTP options:\n\
  -nr, --dont-remove-listing   don\'t remove `.listing\' files.\n\
