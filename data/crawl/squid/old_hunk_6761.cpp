usage(const char *progname)
{
    fprintf(stderr,
	"Usage: %s [-ars] [-i IMS] [-h host] [-p port] [-m method] [-t count] [-I ping-interval] url\n"
	"Options:\n"
	"    -P file      PUT request.\n"
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
