/* $Id: debug.cc,v 1.5 1996/03/27 18:15:42 wessels Exp $ */

#include "squid.h"

char *_db_file = __FILE__;
int _db_line = 0;

int syslog_enable = 0;
int stderr_enable = 0;
FILE *debug_log = NULL;
static char *debug_log_file = NULL;
static time_t last_cached_curtime = 0;
static char the_time[81];

#define MAX_DEBUG_SECTIONS 50
static int debugLevels[MAX_DEBUG_SECTIONS];

#if defined(__STRICT_ANSI__)
void _db_print(int section,...)
{
    va_list args;
#else
void _db_print(va_alist)
     va_dcl
{
    va_list args;
    int section;
#endif
    int level;
    char *format = NULL;
    static char f[BUFSIZ];
    static char tmpbuf[BUFSIZ];
    char *s = NULL;

    if (debug_log == NULL)
	return;

#if defined(__STRICT_ANSI__)
    va_start(args, section);
#else
    va_start(args);
    section = va_arg(args, int);
#endif
    level = va_arg(args, int);
    format = va_arg(args, char *);

    if (debugLevels[section] > level) {
	va_end(args);
	return;
    }
    /* don't compute the curtime too much */
    if (last_cached_curtime != cached_curtime) {
	last_cached_curtime = cached_curtime;
	the_time[0] = '\0';
	s = mkhttpdlogtime(&cached_curtime);
	strcpy(the_time, s);
    }
    sprintf(f, "[%s] %s:%d:\t %s",
	the_time,
	_db_file,
	_db_line,
	format);

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
    va_end(args);
}

static void debugArg(arg)
	char *arg;
{
	int s = 0;
	int l = 0;
	int i;

	if (!strncasecmp(arg, "ALL", 3)) {
		s = -1;
		arg += 4;
	} else {
		s = atoi(arg);
		while (*arg && *arg++ != ',');
	}
	l = atoi (arg);

	if (s >= 0) {
		debugLevels[s] = l;
		return;
	}
	for (i = 0; i < MAX_DEBUG_SECTIONS; i++)
        	debugLevels[i] = l;
}

void _db_init(prefix, logfile)
     char *prefix;
     char *logfile;
{
    int i;
    char *p = NULL;
    char *s = NULL;

    for (i = 0; i < MAX_DEBUG_SECTIONS; i++)
	debugLevels[i] = -1;

    if ((p = getDebugOptions())) {
	p = xstrdup(p);
	for (s=strtok(p, w_space); s; s=strtok(NULL, w_space)) {
	    debugArg(s);
	}
	xfree(p);
    }

    /* open error logging file */
    if (logfile != NULL) {
