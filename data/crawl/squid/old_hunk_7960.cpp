/* $Id: debug.cc,v 1.4 1996/03/27 05:12:38 wessels Exp $ */

#include "squid.h"

extern int getLogfileRotateNumber _PARAMS((void));

static char *_db_modules = 0;	/* colon separated list of modules to debug. */
int _db_level = 0;
char *_db_file = __FILE__;
int _db_line = 0;

extern char *mkrfc850();
extern int unbuffered_logs;	/* main.c */

int syslog_enable = 0;
int stderr_enable = 0;
FILE *debug_log = NULL;
static char *debug_log_file = NULL;
static time_t last_cached_curtime = 0;
static char the_time[81];

#if defined(__STRICT_ANSI__)
void _db_print(int level,...)
{
    char *format;
    va_list args;
#else
void _db_print(va_alist)
     va_dcl
{
    char *format;
    int level;
    va_list args;
#endif
    static char f[BUFSIZ];
    static char tmpbuf[BUFSIZ];
    char *module = NULL;
    char *s = NULL;

    if (debug_log == NULL)
	return;

#if defined(__STRICT_ANSI__)
    /* strict ANSI compliance requires the second arg to va_start - we don't */
    va_start(args, level);
    format = va_arg(args, char *);
#else
    va_start(args);
    level = va_arg(args, int);
    format = va_arg(args, char *);
#endif

    /* Obtain module name from filename. */
    if ((module = strrchr(_db_file, '/')) != NULL)
	module++;
    else
	module = _db_file;

    if (_db_level >= level) {
	if (!_db_modules || strstr(_db_modules, module)) {
	    /* don't compute the curtime too much */
	    if (last_cached_curtime != cached_curtime) {
		last_cached_curtime = cached_curtime;
		the_time[0] = '\0';
		s = mkhttpdlogtime(&cached_curtime);
		strcpy(the_time, s);
	    }
	    sprintf(f, "[%s] %s:%d:\t %s", the_time, module, _db_line, format);

#if HAVE_SYSLOG
	    /* level 0 go to syslog */
	    if ((level == 0) && syslog_enable) {
		tmpbuf[0] = '\0';
		vsprintf(tmpbuf, f, args);
		syslog(LOG_ERR, tmpbuf);
	    }
#endif /* HAVE_SYSLOG */
	    /* write to log file */
	    vfprintf(debug_log, f, args);
	    if (unbuffered_logs)
		fflush(debug_log);

	    /* if requested, dump it to stderr also */
	    if (stderr_enable) {
		vfprintf(stderr, f, args);
		fflush(stderr);
	    }
	}
    }
    va_end(args);
}

void _db_init(prefix, initial_level, logfile)
     char *prefix;
     int initial_level;
     char *logfile;
{
    char *db_level_str, db_buf[MAXPATHLEN];

    sprintf(db_buf, "%s_debug_level", prefix);
    if ((db_level_str = getenv(db_buf)) != NULL)
	_db_level = atoi(db_level_str);
    else
	_db_level = initial_level;

    _db_modules = getenv("DHT_DEBUG_MODULES");

    /* open error logging file */
    if (logfile != NULL) {
