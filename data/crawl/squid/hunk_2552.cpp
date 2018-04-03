 FtpStateData::abortTransaction(const char *reason)
 {
     debugs(9, 3, HERE << "aborting transaction for " << reason <<
-           "; FD " << ctrl.fd << ", Data FD " << data.fd << ", this " << this);
-    if (ctrl.fd >= 0) {
-        comm_close(ctrl.fd);
+           "; FD " << (ctrl.conn!=NULL?ctrl.conn->fd:-1) << ", Data FD " << (data.conn!=NULL?data.conn->fd:-1) << ", this " << this);
+    if (Comm::IsConnOpen(ctrl.conn)) {
+        ctrl.conn->close();
         return;
     }
 
