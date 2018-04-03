 
 };
 
+void ICAPOptions::cfgTransferListHeader(const HttpHeader *h, const char *fname, transfer_type t_type)
+{
+    const String s = httpHeaderGetByName(h, fname);
+
+    if (!s.size())
+        return;
+
+    if (t_type == TRANSFER_PREVIEW)
+        transfers.preview = parseExtFileList(s.buf(), s.buf() + s.size(), t_type);
+    else if (t_type == TRANSFER_IGNORE)
+        transfers.ignore = parseExtFileList(s.buf(), s.buf() + s.size(), t_type);
+    else if (t_type == TRANSFER_COMPLETE)
+        transfers.complete = parseExtFileList(s.buf(), s.buf() + s.size(), t_type);
+    else
+        fatalf("Unexpected transfer_type at %s:%d", __FILE__,__LINE__);
+}
+
 List<String> *ICAPOptions::parseExtFileList(const char *start, const char *end, transfer_type t_type)
 {
-    const String s = xstrndup(start, end - start - 1);
+    const String s = xstrndup(start, end - start + 1);
     const char *item;
     const char *pos = NULL;
     char *fext = NULL;
