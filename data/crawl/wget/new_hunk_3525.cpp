  -T,  --timeout=SECONDS        set the read timeout to SECONDS.\n\
  -w,  --wait=SECONDS           wait SECONDS between retrievals.\n\
       --waitretry=SECONDS      wait 1...SECONDS between retries of a retrieval.\n\
       --random-wait            wait from 0...2*WAIT secs between retrievals.\n\
  -Y,  --proxy=on/off           turn proxy on or off.\n\
  -Q,  --quota=NUMBER           set retrieval quota to NUMBER.\n\
\n"), stdout);
#ifdef HAVE_RANDOM
  fputs (_("\
\n"), stdout);
#endif
  fputs (_("\
Directories:\n\
  -nd  --no-directories            don\'t create directories.\n\
