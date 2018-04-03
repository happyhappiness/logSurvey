#define ALL_ONES (unsigned long) 0xFFFFFFFF
#endif

extern int storeGetSwapSpace _PARAMS((int));
extern void fatal_dump _PARAMS((char *));

static fileMap *fm = NULL;

fileMap *file_map_create(n)
     int n;			/* Number of files */
{
    fm = xcalloc(1, sizeof(fileMap));
    fm->max_n_files = n;
