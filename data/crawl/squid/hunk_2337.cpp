 #include "config.h"
 #include "ipc/UdsOp.h"
 
-void Ipc::SendMessage(const String& toAddress, const TypedMsgHdr& message)
-{
-    fatal ("Not implemented");
-}
+#define STUB_API "UdsOp.cc"
+#include "tests/STUB.h"
+
+void Ipc::SendMessage(const String& toAddress, const TypedMsgHdr& message) STUB
