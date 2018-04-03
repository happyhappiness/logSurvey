#define COMM_REUSEADDR		0x04

#include "Debug.h"
#define do_debug(SECTION, LEVEL) ((Debug::level = (LEVEL)) > Debug::Levels[SECTION])
#define debug(SECTION, LEVEL) \
        do_debug(SECTION, LEVEL) ? (void) 0 : _db_print

#define safe_free(x)	if (x) { xxfree(x); x = NULL; }
