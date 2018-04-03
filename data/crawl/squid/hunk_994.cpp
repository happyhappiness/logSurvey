 
     MemBuf mb;
     mb.init();
-    mb.Printf("%i %s\r\n", code, msg);
+    mb.appendf("%i %s\r\n", code, msg);
 
     typedef CommCbMemFunT<Server, CommIoCbParams> Dialer;
     AsyncCall::Pointer call = JobCallback(33, 5, Dialer, this, Ftp::Server::wroteEarlyReply);
