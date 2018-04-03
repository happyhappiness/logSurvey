#define COMM_NOCLOEXEC		0x02
#define COMM_REUSEADDR		0x04

#define debug(SECTION, LEVEL) \
        ((_db_level = (LEVEL)) > debugLevels[SECTION]) ? (void) 0 : _db_print

#define safe_free(x)	if (x) { xxfree(x); x = NULL; }

