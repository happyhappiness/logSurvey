#define old_debug(SECTION, LEVEL)  if( (Debug::level=(LEVEL)) <= Debug::Levels[SECTION] ) _db_print

/* Legacy debug function definitions */
SQUIDCEXTERN void _db_print(const char *,...) PRINTF_FORMAT_ARG1;

#endif /* SQUID_DEBUG_H */
