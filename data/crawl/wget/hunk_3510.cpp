        --random-wait            wait from 0...2*WAIT secs between retrievals.\n\
   -Y,  --proxy=on/off           turn proxy on or off.\n\
   -Q,  --quota=NUMBER           set retrieval quota to NUMBER.\n\
+       --limit-rate=RATE        limit download rate to RATE.\n\
 \n"), stdout);
 #ifdef HAVE_RANDOM
   fputs (_("\
