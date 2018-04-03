 extern void InvokeHandlers(StoreEntry *);
 extern int storeEntryValidToSend(StoreEntry *);
 extern void storeTimestampsSet(StoreEntry *);
-extern unsigned int storeReqnum(StoreEntry * entry, method_t);
 extern time_t storeExpiredReferenceAge(void);
 extern void storeRegisterAbort(StoreEntry * e, STABH * cb, void *);
 extern void storeUnregisterAbort(StoreEntry * e);
 extern void storeMemObjectDump(MemObject * mem);
+extern const char *storeUrl(const StoreEntry *);
+
+/* storeKey stuff */
+extern const cache_key *storeKeyDup(const cache_key *);
+extern void storeKeyFree(const cache_key *);
+extern const cache_key *storeKeyScan(const char *);
+extern const char *storeKeyText(const cache_key *);
+extern const cache_key *storeKeyPublic(const char *, method_t);
+extern const cache_key *storeKeyPrivate(const char *, method_t, int);
+extern HASHHASH storeKeyHashHash;
+extern HASHCMP storeKeyHashCmp;
 
 #ifdef __STDC__
 extern void storeAppendPrintf(StoreEntry *, const char *,...);
