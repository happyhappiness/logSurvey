     int N = 0;
     int obj_size;
 
-    storeAppendPrintf(sentry, "{\n");
+    storeAppendPrintf(sentry, open_bracket);
 
     for (entry = storeGetFirst();
 	entry != NULL;
