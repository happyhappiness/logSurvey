     }
 
     fwd->handleUnregisteredServerEnd();
-    mustStop("ServerStateData::abortTransaction");
+    mustStop("Ftp::Client::abortTransaction");
 }
 
 /**
  * Cancel the timeout on the Control socket and establish one
  * on the data socket
  */
 void
-ServerStateData::switchTimeoutToDataChannel()
+Ftp::Client::switchTimeoutToDataChannel()
 {
     commUnsetConnTimeout(ctrl.conn);
 
-    typedef CommCbMemFunT<ServerStateData, CommTimeoutCbParams> TimeoutDialer;
+    typedef CommCbMemFunT<Client, CommTimeoutCbParams> TimeoutDialer;
     AsyncCall::Pointer timeoutCall = JobCallback(9, 5, TimeoutDialer, this,
-                                                 ServerStateData::timeout);
+                                                 Ftp::Client::timeout);
     commSetConnTimeout(data.conn, Config.Timeout.read, timeoutCall);
 }
 
 void
-ServerStateData::sentRequestBody(const CommIoCbParams &io)
+Ftp::Client::sentRequestBody(const CommIoCbParams &io)
 {
     if (io.size > 0)
         kb_incr(&(statCounter.server.ftp.kbytes_out), io.size);
