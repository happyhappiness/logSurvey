         storeAppendPrintf(&sentry, " READ-ONLY");
 
     storeAppendPrintf(&sentry, "\n");
+
+    IO->statfs(sentry);
 }
 
 void
