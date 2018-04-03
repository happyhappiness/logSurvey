#define COMM_NOCLOEXEC		0x02
#define COMM_REUSEADDR		0x04

#ifdef HAVE_SYSLOG
#define debug(SECTION, LEVEL) \
        ((_db_level = (LEVEL)) > debugLevels[SECTION]) ? (void) 0 : _db_print
#else
#define debug(SECTION, LEVEL) \
        ((LEVEL) > debugLevels[SECTION]) ? (void) 0 : _db_print
#endif

#define safe_free(x)	if (x) { xxfree(x); x = NULL; }

