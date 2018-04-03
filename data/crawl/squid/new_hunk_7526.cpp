#define ALL_ONES (unsigned long) 0xFFFFFFFF
#endif

extern int storeGetSwapSpace __P((int));
extern void fatal_dump __P((char *));

static fileMap *fm = NULL;

