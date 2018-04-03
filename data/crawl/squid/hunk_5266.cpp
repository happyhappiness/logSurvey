         if (s->capath)
             storeAppendPrintf(e, " capath=%s", s->capath);
 
+        if (s->dhfile)
+            storeAppendPrintf(e, " dhparams=%s", s->dhfile);
+
         if (s->sslflags)
             storeAppendPrintf(e, " sslflags=%s", s->sslflags);
 
