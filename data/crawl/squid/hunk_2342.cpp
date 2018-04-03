 /* because the clientdb API is defined in protos.h still */
 #include "protos.h"
 
-void
-clientdbInit(void)
-{
-    fatal("client_db.cc required");
-}
-
-void
-clientdbUpdate(const Ip::Address &, log_type, AnyP::ProtocolType, size_t)
-{
-    fatal("client_db.cc required");
-}
-
-int
-clientdbCutoffDenied(const Ip::Address &)
-{
-    fatal("client_db.cc required");
-    return -1;
-}
-
-void
-clientdbDump(StoreEntry *)
-{
-    fatal("client_db.cc required");
-}
-
-void
-clientdbFreeMemory(void)
-{
-    fatal("client_db.cc required");
-}
-
-int
-clientdbEstablished(const Ip::Address &, int)
-{
-    fatal("client_db.cc required");
-    return -1;
-}
-
+#define STUB_API "client_db.cc"
+#include "tests/STUB.h"
+
+void clientdbInit(void) STUB
+void clientdbUpdate(const Ip::Address &, log_type, AnyP::ProtocolType, size_t) STUB
+int clientdbCutoffDenied(const Ip::Address &) STUB_RETVAL(-1)
+void clientdbDump(StoreEntry *) STUB
+void clientdbFreeMemory(void) STUB
+int clientdbEstablished(const Ip::Address &, int) STUB_RETVAL(-1)
 #if USE_DELAY_POOLS
-void
-clientdbSetWriteLimiter(ClientInfo * info, const int writeSpeedLimit,const double initialBurst,const double highWatermark)
-{
-    fatal("client_db.cc required");
-}
-
-ClientInfo *
-clientdbGetInfo(const Ip::Address &addr)
-{
-    fatal("client_db.cc required");
-    return NULL;
-}
+void clientdbSetWriteLimiter(ClientInfo * info, const int writeSpeedLimit,const double initialBurst,const double highWatermark) STUB
+ClientInfo *clientdbGetInfo(const Ip::Address &addr) STUB_RETVAL(NULL)
 #endif
-
-void
-clientOpenListenSockets(void)
-{
-    fatal("client_db.cc required");
-}
-
-void
-clientHttpConnectionsClose(void)
-{
-    fatal("client_db.cc required");
-}
+void clientOpenListenSockets(void) STUB
+void clientHttpConnectionsClose(void) STUB
