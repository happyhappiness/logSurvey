 // because ipcCreate is defined in protos.h still
 #include "protos.h"
 
-pid_t
-ipcCreate(int type, const char *prog, const char *const args[], const char *name, Ip::Address &local_addr, int *rfd, int *wfd, void **hIpc)
-{
-    fatal("ipc.cc required.");
-    return -1;
-}
+#define STUB_API "ipc.cc"
+#include "tests/STUB.h"
+
+pid_t ipcCreate(int, const char *, const char *const [], const char *, Ip::Address &, int *, int *, void **) STUB_RETVAL(-1)
