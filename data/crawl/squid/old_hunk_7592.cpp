static time_t mainMaintenance _PARAMS((void));
static void usage _PARAMS((void));
static void mainParseOptions _PARAMS((int, char **));

static void usage()
{
    fprintf(stderr, "\
Usage: %s [-hsvzCDFRUVY] [-f config-file] [-[au] port]\n\
       -a port   Specify ASCII port number (default: %d).\n\
       -f file   Use given config-file instead of\n\
                 %s\n\
       -i        Disable IP caching.\n\
       -h        Print help message.\n\
       -s        Enable logging to syslog.\n\
       -u port   Specify ICP port number (default: %d), disable with 0.\n\
       -v        Print version.\n\
