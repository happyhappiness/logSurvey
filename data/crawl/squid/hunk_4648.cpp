     if (!flags.http_header_sent && data.readBuf->contentSize() >= 0)
         appendSuccessHeader();
 
+    if (EBIT_TEST(entry->flags, ENTRY_ABORTED)) {
+	/*
+	 * probably was aborted because content length exceeds one
+	 * of the maximum size limits.
+	 */
+        abortTransaction("entry aborted after calling appendSuccessHeader()");
+        return;
+    }
+
 #if ICAP_CLIENT
 
     if (icapAccessCheckPending) {