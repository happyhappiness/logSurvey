     return os;
 }
 
-SQUIDCEXTERN size_t storeEntryInUse() STUB_RETVAL(0)
-SQUIDCEXTERN const char *storeEntryFlags(const StoreEntry *) STUB_RETVAL(NULL)
+size_t storeEntryInUse() STUB_RETVAL(0)
+const char *storeEntryFlags(const StoreEntry *) STUB_RETVAL(NULL)
 void storeEntryReplaceObject(StoreEntry *, HttpReply *) STUB
-SQUIDCEXTERN StoreEntry *storeGetPublic(const char *uri, const HttpRequestMethod& method) STUB_RETVAL(NULL)
-SQUIDCEXTERN StoreEntry *storeGetPublicByRequest(HttpRequest * request) STUB_RETVAL(NULL)
-SQUIDCEXTERN StoreEntry *storeGetPublicByRequestMethod(HttpRequest * request, const HttpRequestMethod& method) STUB_RETVAL(NULL)
-SQUIDCEXTERN StoreEntry *storeCreateEntry(const char *, const char *, request_flags, const HttpRequestMethod&) STUB_RETVAL(NULL)
-SQUIDCEXTERN void storeInit(void) STUB
-SQUIDCEXTERN void storeConfigure(void) STUB
-SQUIDCEXTERN void storeFreeMemory(void) STUB
-SQUIDCEXTERN int expiresMoreThan(time_t, time_t) STUB_RETVAL(0)
-SQUIDCEXTERN void storeAppendPrintf(StoreEntry *, const char *,...) STUB
+StoreEntry *storeGetPublic(const char *uri, const HttpRequestMethod& method) STUB_RETVAL(NULL)
+StoreEntry *storeGetPublicByRequest(HttpRequest * request) STUB_RETVAL(NULL)
+StoreEntry *storeGetPublicByRequestMethod(HttpRequest * request, const HttpRequestMethod& method) STUB_RETVAL(NULL)
+extern StoreEntry *storeCreateEntry(const char *, const char *, const RequestFlags &, const HttpRequestMethod&) STUB_RETVAL(NULL)
+void storeInit(void) STUB
+void storeConfigure(void) STUB
+void storeFreeMemory(void) STUB
+int expiresMoreThan(time_t, time_t) STUB_RETVAL(0)
+void storeAppendPrintf(StoreEntry *, const char *,...) STUB
 void storeAppendVPrintf(StoreEntry *, const char *, va_list ap) STUB
-SQUIDCEXTERN int storeTooManyDiskFilesOpen(void) STUB_RETVAL(0)
-SQUIDCEXTERN void storeHeapPositionUpdate(StoreEntry *, SwapDir *) STUB
-SQUIDCEXTERN void storeSwapFileNumberSet(StoreEntry * e, sfileno filn) STUB
-SQUIDCEXTERN void storeFsInit(void) STUB
-SQUIDCEXTERN void storeFsDone(void) STUB
-SQUIDCEXTERN void storeReplAdd(const char *, REMOVALPOLICYCREATE *) STUB
+int storeTooManyDiskFilesOpen(void) STUB_RETVAL(0)
+void storeHeapPositionUpdate(StoreEntry *, SwapDir *) STUB
+void storeSwapFileNumberSet(StoreEntry * e, sfileno filn) STUB
+void storeFsInit(void) STUB
+void storeFsDone(void) STUB
+void storeReplAdd(const char *, REMOVALPOLICYCREATE *) STUB
 void destroyStoreEntry(void *) STUB
-// in Packer.cc !? SQUIDCEXTERN void packerToStoreInit(Packer * p, StoreEntry * e) STUB
-SQUIDCEXTERN void storeGetMemSpace(int size) STUB
+// in Packer.cc !? void packerToStoreInit(Packer * p, StoreEntry * e) STUB
+void storeGetMemSpace(int size) STUB
 
 #if !_USE_INLINE_
 #include "Store.cci"
