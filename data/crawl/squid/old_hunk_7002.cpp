extern void InvokeHandlers(StoreEntry *);
extern int storeEntryValidToSend(StoreEntry *);
extern void storeTimestampsSet(StoreEntry *);
extern unsigned int storeReqnum(StoreEntry * entry, method_t);
extern time_t storeExpiredReferenceAge(void);
extern void storeRegisterAbort(StoreEntry * e, STABH * cb, void *);
extern void storeUnregisterAbort(StoreEntry * e);
extern void storeMemObjectDump(MemObject * mem);

#ifdef __STDC__
extern void storeAppendPrintf(StoreEntry *, const char *,...);
