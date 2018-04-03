#endif

/* Local functions */
static int client_comm_connect(int sock, char *dest_host, u_short dest_port);
static void usage(const char *progname);

static void
usage(const char *progname)
{
    fprintf(stderr,
	"Usage: %s [-ars] [-i IMS] [-h host] [-p port] [-m method] [-t count] url\n"
	"Options:\n"
	"    -a         Do NOT include Accept: header.\n"
	"    -r         Force cache to reload URL.\n"
	"    -s         Silent.  Do not print data to stdout.\n"
	"    -i IMS     If-Modified-Since time (in Epoch seconds).\n"
	"    -h host    Retrieve URL from cache on hostname.  Default is localhost.\n"
	"    -p port    Port number of cache.  Default is %d.\n"
	"    -m method  Request method, default is GET.\n"
	"    -t count   Trace count cache-hops\n",
	progname, CACHE_HTTP_PORT);
    exit(1);
}

int
main(int argc, char *argv[])
{
    int conn, c, len, bytesWritten;
    int port, to_stdout, reload;
    int keep_alive = 0;
    int opt_noaccept = 0;
    char url[BUFSIZ], msg[BUFSIZ], buf[BUFSIZ], hostname[BUFSIZ];
    const char *method = "GET";
    extern char *optarg;
    time_t ims = 0;
    int max_forwards = -1;

    /* set the defaults */
    strcpy(hostname, "localhost");
    port = CACHE_HTTP_PORT;
    to_stdout = 1;
    reload = 0;

    if (argc < 2) {
	usage(argv[0]);		/* need URL */
    } else if (argc >= 2) {
	strcpy(url, argv[argc - 1]);
	if (url[0] == '-')
	    usage(argv[0]);
	while ((c = getopt(argc, argv, "ah:i:km:p:rst:?")) != -1)
	    switch (c) {
	    case 'a':
		opt_noaccept = 1;
