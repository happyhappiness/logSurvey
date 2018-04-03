
#if STDC_HEADERS
extern void
_db_print(const char *,...) PRINTF_FORMAT_ARG(1);
#else
extern void _db_print();
#endif
