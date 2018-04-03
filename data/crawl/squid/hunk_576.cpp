     }
     memcpy(nargs,argv+nstart+1,(nend-nstart)*sizeof(char *));
     nargs[nend-nstart]=NULL;
-    if (debug) {
+    if (debug_enabled) {
         fprintf(stderr, "%s| %s: NTLM command: ", LogTime(), PROGRAM);
         for (int i=0; i<nend-nstart; ++i)
             fprintf(stderr, "%s ", nargs[i]);
