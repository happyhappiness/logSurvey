         comm_close(data.fd);
         data.fd = -1;
     }
+}
 
-#if ICAP_CLIENT
-
-    if (icap) {
-        icap->doneSending();
-        return;
-    }
-
-#endif
-
-    transactionForwardComplete();
+// Did we close all FTP server connection(s)?
+bool
+FtpStateData::doneWithServer() const
+{
+    return ctrl.fd < 0 && data.fd < 0;
+}
 
-    ftpSocketClosed(-1, this);
+// Quickly abort the transaction
+// TODO: destruction should be sufficient as the destructor should cleanup,
+// including canceling close handlers
+void
+FtpStateData::abortTransaction(const char *reason)
+{
+    debugs(9,5,HERE << "aborting transaction for " << reason <<
+        "; FD " << ctrl.fd << ", Data FD " << data.fd << ", this " << this);
+    if (ctrl.fd >= 0)
+        comm_close(ctrl.fd);
+    else
+        delete this;
 }
 
 #if ICAP_CLIENT
