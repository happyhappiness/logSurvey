       --bind-address=ADDRESS   bind to ADDRESS (hostname or IP) on local host.\n\
       --limit-rate=RATE        limit download rate to RATE.\n\
       --dns-cache=off          disable caching DNS lookups.\n\
       --restrict-file-names=MODE restrict chars in file names to MODE.\n\
\n"), stdout);
  fputs (_("\
Directories:\n\
  -nd, --no-directories            don\'t create directories.\n\
  -x,  --force-directories         force creation of directories.\n\
  -nH, --no-host-directories       don\'t create host directories.\n\
  -P,  --directory-prefix=PREFIX   save files to PREFIX/...\n\
