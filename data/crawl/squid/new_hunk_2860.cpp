static void mcast_encode(unsigned int *, size_t, const unsigned int *);
#endif

#if USE_FORW_VIA_DB

typedef struct {
    hash_link hash;
    int n;
} fvdb_entry;
static hash_table *via_table = NULL;
static hash_table *forw_table = NULL;
static void fvdbInit();
static void fvdbDumpTable(StoreEntry * e, hash_table * hash);
static void fvdbCount(hash_table * hash, const char *key);
static OBJH fvdbDumpVia;
static OBJH fvdbDumpForw;
static FREE fvdbFreeEntry;
static void fvdbClear(void);
static void fvdbRegisterWithCacheManager();
#endif

int LogfileStatus = LOG_DISABLE;

void
accessLogLogTo(customlog* log, AccessLogEntry * al, ACLChecklist * checklist)
