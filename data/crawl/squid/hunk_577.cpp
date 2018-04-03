     }
     memcpy(kargs,argv+kstart+1,(kend-kstart)*sizeof(char *));
     kargs[kend-kstart]=NULL;
-    if (debug) {
+    if (debug_enabled) {
         fprintf(stderr, "%s| %s: Kerberos command: ", LogTime(), PROGRAM);
         for (int i=0; i<kend-kstart; ++i)
             fprintf(stderr, "%s ", kargs[i]);
