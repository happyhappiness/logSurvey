  -i,  --input-file=FILE      download URLs found in FILE.\n\
  -F,  --force-html           treat input file as HTML.\n\
  -B,  --base=URL             prepends URL to relative links in -F -i file.\n\
       --sslcertfile=FILE     optional client certificate.\n\
       --sslcertkey=KEYFILE   optional keyfile for this certificate.\n\
       --egd-file=FILE        file name of the EGD socket.\n\
\n"), stdout);
  fputs (_("\
Download:\n\
       --bind-address=ADDRESS   bind to ADDRESS (hostname or IP) on local host.\n\
  -t,  --tries=NUMBER           set number of retries to NUMBER (0 unlimits).\n\
  -O   --output-document=FILE   write documents to FILE.\n\
  -nc, --no-clobber             don\'t clobber existing files or use .# suffixes.\n\
