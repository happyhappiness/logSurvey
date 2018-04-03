     commSetTimeout(ftpState->data.fd, 15, FtpStateData::ftpTimeout, ftpState);
 }
 
+void
+FtpStateData::processHeadResponse()
+{
+    debugs(9, 5, HERE << "handling HEAD response");
+    ftpSendQuit(this);
+    appendSuccessHeader();
+
+    /*
+     * On rare occasions I'm seeing the entry get aborted after
+     * ftpReadControlReply() and before here, probably when
+     * trying to write to the client.
+     */
+    if (EBIT_TEST(entry->flags, ENTRY_ABORTED)) {
+        abortTransaction("entry aborted while processing HEAD");
+        return;
+    }
+
+#if ICAP_CLIENT
+    if (icapAccessCheckPending) {
+        debugs(9,3,HERE << "returning from ftpSendPasv due to icapAccessCheckPending");
+        return;
+    }
+#endif
+
+    // processReplyBody calls serverComplete() since there is no body
+    processReplyBody(); 
+}
+
 static void
 ftpReadPasv(FtpStateData * ftpState)
 {
