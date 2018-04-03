 ClientSocketContext::initiateClose(const char *reason)
 {
     debugs(33, 5, HERE << "initiateClose: closing for " << reason);
+
     if (http != NULL) {
         ConnStateData::Pointer conn = http->getConn();
 
