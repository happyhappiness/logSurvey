     nargs[nend-nstart]=NULL;
     if (debug) {
         fprintf(stderr, "%s| %s: NTLM command: ", LogTime(), PROGRAM);
-        for (i=0; i<nend-nstart; i++)
+        for (i=0; i<nend-nstart; ++i)
             fprintf(stderr, "%s ", nargs[i]);
         fprintf(stderr, "\n");
     }
