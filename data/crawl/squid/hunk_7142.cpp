 statFiledescriptors(StoreEntry * sentry)
 {
     int i;
-    FD_ENTRY *f;
+    fde *f;
 
     storeAppendPrintf(sentry, open_bracket);
     storeAppendPrintf(sentry, "{Active file descriptors:}\n");
