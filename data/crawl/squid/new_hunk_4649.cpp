
SQUIDCEXTERN size_t storeEntryInUse();
SQUIDCEXTERN const char *storeEntryFlags(const StoreEntry *);
extern void storeEntryReplaceObject(StoreEntry *, HttpReply *);

SQUIDCEXTERN StoreEntry *storeGetPublic(const char *uri, const method_t method);
SQUIDCEXTERN StoreEntry *storeGetPublicByRequest(HttpRequest * request);
SQUIDCEXTERN StoreEntry *storeGetPublicByRequestMethod(HttpRequest * request, const method_t method);
SQUIDCEXTERN StoreEntry *storeCreateEntry(const char *, const char *, request_flags, method_t);
SQUIDCEXTERN void storeInit(void);
extern void storeRegisterWithCacheManager(CacheManager & manager);
SQUIDCEXTERN void storeConfigure(void);
SQUIDCEXTERN void storeFreeMemory(void);
SQUIDCEXTERN int expiresMoreThan(time_t, time_t);
#if STDC_HEADERS
SQUIDCEXTERN void
storeAppendPrintf(StoreEntry *, const char *,...) PRINTF_FORMAT_ARG2;
#else
SQUIDCEXTERN void storeAppendPrintf();
#endif
SQUIDCEXTERN void storeAppendVPrintf(StoreEntry *, const char *, va_list ap);
SQUIDCEXTERN ssize_t objectLen(const StoreEntry * e);
SQUIDCEXTERN int storeTooManyDiskFilesOpen(void);
SQUIDCEXTERN void storeHeapPositionUpdate(StoreEntry *, SwapDir *);
SQUIDCEXTERN void storeSwapFileNumberSet(StoreEntry * e, sfileno filn);
SQUIDCEXTERN void storeFsInit(void);
