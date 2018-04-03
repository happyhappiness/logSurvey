 StoreEntry *storeGetPublicByRequestMethod(HttpRequest * request, const HttpRequestMethod& method) STUB_RETVAL(NULL)
 StoreEntry *storeCreateEntry(const char *, const char *, const RequestFlags &, const HttpRequestMethod&) STUB_RETVAL(NULL)
 StoreEntry *storeCreatePureEntry(const char *storeId, const char *logUrl, const RequestFlags &, const HttpRequestMethod&) STUB_RETVAL(NULL)
-void storeInit(void) STUB
 void storeConfigure(void) STUB
-void storeFreeMemory(void) STUB
 int expiresMoreThan(time_t, time_t) STUB_RETVAL(0)
 void storeAppendPrintf(StoreEntry *, const char *,...) STUB
 void storeAppendVPrintf(StoreEntry *, const char *, va_list ap) STUB
