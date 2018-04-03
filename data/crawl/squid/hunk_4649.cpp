 
 SQUIDCEXTERN size_t storeEntryInUse();
 SQUIDCEXTERN const char *storeEntryFlags(const StoreEntry *);
-SQUIDCEXTERN int storeEntryLocked(const StoreEntry *);
 extern void storeEntryReplaceObject(StoreEntry *, HttpReply *);
 
 SQUIDCEXTERN StoreEntry *storeGetPublic(const char *uri, const method_t method);
 SQUIDCEXTERN StoreEntry *storeGetPublicByRequest(HttpRequest * request);
 SQUIDCEXTERN StoreEntry *storeGetPublicByRequestMethod(HttpRequest * request, const method_t method);
 SQUIDCEXTERN StoreEntry *storeCreateEntry(const char *, const char *, request_flags, method_t);
-SQUIDCEXTERN void storeCreateMemObject(StoreEntry *, const char *, const char *);
 SQUIDCEXTERN void storeInit(void);
 extern void storeRegisterWithCacheManager(CacheManager & manager);
-SQUIDCEXTERN void storeAppend(StoreEntry *, const char *, int);
 SQUIDCEXTERN void storeConfigure(void);
-SQUIDCEXTERN int storeCheckNegativeHit(StoreEntry *);
 SQUIDCEXTERN void storeFreeMemory(void);
 SQUIDCEXTERN int expiresMoreThan(time_t, time_t);
-SQUIDCEXTERN int storeEntryValidToSend(StoreEntry *);
-SQUIDCEXTERN void storeTimestampsSet(StoreEntry *);
-SQUIDCEXTERN void storeRegisterAbort(StoreEntry * e, STABH * cb, void *);
-SQUIDCEXTERN void storeUnregisterAbort(StoreEntry * e);
-SQUIDCEXTERN void storeEntryDump(const StoreEntry * e, int debug_lvl);
-SQUIDCEXTERN const char *storeUrl(const StoreEntry *);
-SQUIDCEXTERN void storeBuffer(StoreEntry *);
-SQUIDCEXTERN void storeBufferFlush(StoreEntry *);
-SQUIDCEXTERN void storeHashInsert(StoreEntry * e, const cache_key *);
-SQUIDCEXTERN void storeSetMemStatus(StoreEntry * e, mem_status_t);
 #if STDC_HEADERS
 SQUIDCEXTERN void
 storeAppendPrintf(StoreEntry *, const char *,...) PRINTF_FORMAT_ARG2;
 #else
 SQUIDCEXTERN void storeAppendPrintf();
 #endif
 SQUIDCEXTERN void storeAppendVPrintf(StoreEntry *, const char *, va_list ap);
-SQUIDCEXTERN int storeCheckCachable(StoreEntry * e);
 SQUIDCEXTERN ssize_t objectLen(const StoreEntry * e);
 SQUIDCEXTERN int storeTooManyDiskFilesOpen(void);
-SQUIDCEXTERN void storeEntryReset(StoreEntry *);
 SQUIDCEXTERN void storeHeapPositionUpdate(StoreEntry *, SwapDir *);
 SQUIDCEXTERN void storeSwapFileNumberSet(StoreEntry * e, sfileno filn);
 SQUIDCEXTERN void storeFsInit(void);
