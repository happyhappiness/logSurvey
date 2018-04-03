#else
extern void storeAppendPrintf();
#endif
extern int storeCheckCachable(StoreEntry * e);
extern void storeUnlinkFileno(int fileno);
extern void storeSetPrivateKey(StoreEntry *);
