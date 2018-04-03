/* $Id: main.cc,v 1.46 1996/05/03 22:56:29 wessels Exp $ */

/* DEBUG: Section 1             main: startup and main loop */

#include "squid.h"

time_t squid_starttime = 0;
time_t next_cleaning = 0;
int theAsciiConnection = -1;
int theUdpConnection = -1;
int do_reuse = 1;
int opt_unlink_on_reload = 0;
int catch_signals = 1;
int do_dns_test = 1;
int vhost_mode = 0;
int unbuffered_logs = 1;	/* debug and hierarhcy unbuffered by default */
int shutdown_pending = 0;	/* set by SIGTERM handler (shut_down()) */
int reread_pending = 0;		/* set by SIGHUP handler */
char *version_string = SQUID_VERSION;
char *appname = "squid";

extern void (*failure_notify) ();	/* for error reporting from xmalloc */

static int asciiPortNumOverride = 0;
static int udpPortNumOverride = 0;
static int malloc_debug_level = 0;

static void usage()
{
    fprintf(stderr, "\
Usage: %s [-Rsehvz] [-f config-file] [-[apu] port]\n\
       -h        Print help message.\n\
       -s        Enable logging to syslog.\n\
       -v        Print version.\n\
       -z        Zap disk storage -- deletes all objects in disk cache.\n\
       -C        Do not catch fatal signals.\n\
       -D        Disable initial DNS tests.\n\
       -R        Do not set REUSEADDR on port.\n\
       -U        Unlink expired objects on reload.\n\
       -f file   Use given config-file instead of\n\
                 %s\n\
       -a port	 Specify ASCII port number (default: %d).\n\
       -u port	 Specify UDP port number (default: %d).\n",
	appname, DefaultConfigFile, CACHE_HTTP_PORT, CACHE_ICP_PORT);
    exit(1);
}

