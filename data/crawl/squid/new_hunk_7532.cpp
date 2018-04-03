#define ALL_ONES (unsigned long) 0xFFFFFFFF
#endif

extern int storeGetSwapSpace(int);
extern void fatal_dump(char *);

static fileMap *fm = NULL;

fileMap *
file_map_create(int n)
{
    fm = xcalloc(1, sizeof(fileMap));
    fm->max_n_files = n;
