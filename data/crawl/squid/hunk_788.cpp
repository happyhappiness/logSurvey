     if (s->key)
         storeAppendPrintf(e, " key=%s", s->key);
 
-    if (s->version)
-        storeAppendPrintf(e, " version=%d", s->version);
-
     if (s->options)
         storeAppendPrintf(e, " options=%s", s->options);
 
