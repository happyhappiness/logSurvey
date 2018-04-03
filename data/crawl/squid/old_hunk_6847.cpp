extern HASHHASH storeKeyHashHash;
extern HASHCMP storeKeyHashCmp;

#ifdef __STDC__
extern void storeAppendPrintf(StoreEntry *, const char *,...);
#else
extern void storeAppendPrintf();
#endif

extern char *storeSwapFullPath(int, char *);
extern char *storeSwapSubSubDir(int, char *);
extern int storeVerifySwapDirs(void);
