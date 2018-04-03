#define COMM_NOCLOEXEC		0x02
#define COMM_REUSEADDR		0x04

#include "Debug.h"
#define debug(SECTION, LEVEL) \
        ((Debug::level = (LEVEL)) > Debug::Levels[SECTION]) ? (void) 0 : _db_print

#define safe_free(x)	if (x) { xxfree(x); x = NULL; }

