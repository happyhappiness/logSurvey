  *	including canceling close handlers
  */
 void
-ServerStateData::abortTransaction(const char *reason)
+Ftp::Client::abortTransaction(const char *reason)
 {
     debugs(9, 3, HERE << "aborting transaction for " << reason <<
            "; FD " << (ctrl.conn!=NULL?ctrl.conn->fd:-1) << ", Data FD " << (data.conn!=NULL?data.conn->fd:-1) << ", this " << this);
