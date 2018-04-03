 {
     statHistInit(H, last_enum + 3, &Null, &Null, -1, last_enum + 1 + 1);
 }
+
+void
+statHistIntDumper(StoreEntry * sentry, int idx, double val, double size, int count)
+{
+    if (count)
+        storeAppendPrintf(sentry, "%2d\t %5d\t %5d\n",
+            idx, (int) val, count);
+}