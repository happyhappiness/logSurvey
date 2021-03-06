#define old_debug(SECTION, LEVEL)  if do_debug((SECTION), (LEVEL)) _db_print

/* Legacy debug function definitions */
extern void _db_init(const char *logfile, const char *options);
extern void _db_print(const char *,...) PRINTF_FORMAT_ARG1;
extern void _db_set_syslog(const char *facility);
extern void _db_rotate_log(void);

#endif /* SQUID_DEBUG_H */
