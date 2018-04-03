     }
 
 #else
-    storeAppendPrintf(sentry, "detailed allocation information only available when compiled with CBDATA_DEBUG\n");
+    storeAppendPrintf(sentry, "detailed allocation information only available when compiled with --enable-debug-cbdata\n");
 
 #endif
 
