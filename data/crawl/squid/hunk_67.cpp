 #include "SquidTime.h"
 #include "Store.h"
 
-fde *fde::Table = NULL;
+fde *fde::Table = nullptr;
 
 bool
-fde::readPending(int fdNumber)
+fde::readPending(int fdNumber) const
 {
     if (type == FD_SOCKET)
         return Comm::MonitorsRead(fdNumber);
 
-    return read_handler ? true : false ;
+    return read_handler != nullptr;
 }
 
 void
-fde::dumpStats (StoreEntry &dumpEntry, int fdNumber)
+fde::dumpStats(StoreEntry &dumpEntry, int fdNumber) const
 {
     if (!flags.open)
         return;
 
 #if _SQUID_WINDOWS_
-
     storeAppendPrintf(&dumpEntry, "%4d 0x%-8lX %-6.6s %4d %7" PRId64 "%c %7" PRId64 "%c %-21s %s\n",
                       fdNumber,
                       win32.handle,
