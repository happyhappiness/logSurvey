extern void storeHashInsert(StoreEntry * e, const cache_key *);
extern void storeSetMemStatus(StoreEntry * e, int);
#if STDC_HEADERS
extern void
storeAppendPrintf(StoreEntry *, const char *,...) PRINTF_FORMAT_ARG(2);
#else
extern void storeAppendPrintf();
#endif
