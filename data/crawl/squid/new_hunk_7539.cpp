static time_t next_announce;
static time_t next_ip_purge;

static void rotate_logs(int);
static void reconfigure(int);
static void mainInitialize(void);
static void mainReinitialize(void);
static time_t mainMaintenance(void);
static void usage(void);
static void mainParseOptions(int, char **);
static void sendSignal(void);

static void
usage()
{
    fprintf(stderr, "\
Usage: %s [-hsvzCDFRUVY] [-f config-file] [-[au] port] [-k signal]\n\
