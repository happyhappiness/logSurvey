        ((LEVEL) > debugLevels[SECTION]) ? (void) 0 : _db_print
#endif

#define safe_free(x)	if (x) { xxfree(x); x = NULL; }

#define DISK_OK                   (0)