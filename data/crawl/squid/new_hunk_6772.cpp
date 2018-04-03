#else
extern void storeAppendPrintf();
#endif
extern void storeAppendVPrintf(StoreEntry *, const char *, va_list ap);
extern int storeCheckCachable(StoreEntry * e);
extern void storeUnlinkFileno(int fileno);
extern void storeSetPrivateKey(StoreEntry *);
