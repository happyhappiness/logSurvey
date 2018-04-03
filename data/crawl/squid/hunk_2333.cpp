 #include "squid.h"
 #include "CommIO.h"
 
+#define STUB_API "CommIO.cc"
+#include "tests/STUB.h"
+
 bool CommIO::Initialised = false;
 bool CommIO::DoneSignalled = false;
 int CommIO::DoneFD = -1;
 int CommIO::DoneReadFD = -1;
 
-void
-CommIO::ResetNotifications()
-{
-    fatal("Not Implemented");
-}
-
-void
-CommIO::Initialise()
-{
-    fatal("Not Implemented");
-}
-
-void
-CommIO::NotifyIOClose()
-{
-    fatal("Not Implemented");
-}
-
-void
-CommIO::NULLFDHandler(int, void *)
-{
-    fatal("Not Implemented");
-}
-
-void
-CommIO::FlushPipe()
-{
-    fatal("Not Implemented");
-}
+void CommIO::ResetNotifications() STUB
+void CommIO::Initialise() STUB
+void CommIO::NotifyIOClose() STUB
+void CommIO::NULLFDHandler(int, void *) STUB
+void CommIO::FlushPipe() STUB
