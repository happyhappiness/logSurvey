static time_t next_announce;
static time_t next_ip_purge;

static void rotate_logs _PARAMS((int));
static void reconfigure _PARAMS((int));
static void mainInitialize _PARAMS((void));
static void mainReinitialize _PARAMS((void));
static time_t mainMaintenance _PARAMS((void));
static void usage _PARAMS((void));
static void mainParseOptions _PARAMS((int, char **));
static void sendSignal _PARAMS((void));

static void usage()
{
    fprintf(stderr, "\
Usage: %s [-hsvzCDFRUVY] [-f config-file] [-[au] port] [-k signal]\n\
