 #else
     void *p = (void *)&data;
 #endif
-    storeAppendPrintf(sentry, "%c%p\t%d\t%d\t%20s:%-5d\n", valid ? ' ' :
-                      '!', p, type, locks, file, line);
+    storeAppendPrintf(sentry, "%c%p\t%d\t%u\t%20s:%-5d\n", valid ? ' ' :
+                      '!', p, type, LockCount(), file, line);
 }
 
 struct CBDataDumper : public unary_function<cbdata, void> {
