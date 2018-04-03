#endif

/* Local functions */
static int client_comm_connect();
static void usage();

static void usage(progname)
     char *progname;
{
    fprintf(stderr, "\
Usage: %s [-rs] [-i IMS_time] [-h host] [-p port] [-m method] url\n\
