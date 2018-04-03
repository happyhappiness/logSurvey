#endif

/* Local functions */
static int client_comm_connect(int, char *, u_short, struct timeval *);
static void usage(const char *progname);
static int Now(struct timeval *);
static SIGHDLR catch;

static void
usage(const char *progname)
{
    fprintf(stderr,
	"Usage: %s [-ars] [-i IMS] [-h host] [-p port] [-m method] [-t count] [-I ping-interval] url\n"
	"Options:\n"
	"    -a           Do NOT include Accept: header.\n"
	"    -r           Force cache to reload URL.\n"
	"    -s           Silent.  Do not print data to stdout.\n"
	"    -i IMS       If-Modified-Since time (in Epoch seconds).\n"
	"    -h host      Retrieve URL from cache on hostname.  Default is localhost.\n"
	"    -p port      Port number of cache.  Default is %d.\n"
	"    -m method    Request method, default is GET.\n"
	"    -t count     Trace count cache-hops\n"
	"    -g count     Ping mode, \"count\" iterations (0 to loop until interrupted).\n"
	"    -I interval  Ping interval in seconds (default 1 second).\n",
	progname, CACHE_HTTP_PORT);
    exit(1);
}

static int interrupted = 0;
int
main(int argc, char *argv[])
{
    int conn, c, len, bytesWritten;
    int port, to_stdout, reload;
    int ping, pcount;
    int keep_alive = 0;
    int opt_noaccept = 0;
    char url[BUFSIZ], msg[BUFSIZ], buf[BUFSIZ], hostname[BUFSIZ];
    const char *method = "GET";
    extern char *optarg;
    time_t ims = 0;
    int max_forwards = -1;
    struct timeval tv1, tv2;
    int i = 0, loops;
    long ping_int;
    long ping_min = 0, ping_max = 0, ping_sum = 0, ping_mean = 0;

    /* set the defaults */
    strcpy(hostname, "localhost");
    port = CACHE_HTTP_PORT;
    to_stdout = 1;
    reload = 0;
    ping = 0;
    pcount = 0;
    ping_int = 1 * 1000;

    if (argc < 2) {
	usage(argv[0]);		/* need URL */
    } else if (argc >= 2) {
	strcpy(url, argv[argc - 1]);
	if (url[0] == '-')
	    usage(argv[0]);
	while ((c = getopt(argc, argv, "ah:i:km:p:rst:g:I:?")) != -1)
	    switch (c) {
	    case 'a':
		opt_noaccept = 1;
