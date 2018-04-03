usage(const char *progname)
{
    fprintf(stderr,
	"Version: %s\n"
	"Usage: %s [-arsv] [-i IMS] [-h remote host] [-l local host] [-p port] [-m method] [-t count] [-I ping-interval] [-H 'strings'] [-T timeout] url\n"
	"Options:\n"
	"    -P file      PUT request.\n"
	"    -a           Do NOT include Accept: header.\n"
	"    -r           Force cache to reload URL.\n"
	"    -s           Silent.  Do not print data to stdout.\n"
	"    -v           Verbose. Print outgoing message to stderr.\n"
	"    -i IMS       If-Modified-Since time (in Epoch seconds).\n"
	"    -h host      Retrieve URL from cache on hostname.  Default is localhost.\n"
	"    -l host      Specify a local IP address to bind to.  Default is none.\n"
	"    -p port      Port number of cache.  Default is %d.\n"
	"    -m method    Request method, default is GET.\n"
	"    -t count     Trace count cache-hops\n"
	"    -g count     Ping mode, \"count\" iterations (0 to loop until interrupted).\n"
	"    -I interval  Ping interval in seconds (default 1 second).\n"
	"    -H 'string'  Extra headers to send. Use '\\n' for new lines.\n"
	"    -T timeout   Timeout value (seconds) for read/write operations.\n"
	"    -u user      Proxy authentication username\n"
	"    -w password  Proxy authentication password\n"
	"    -U user      WWW authentication username\n"
	"    -W password  WWW authentication password\n",
	VERSION, progname, CACHE_HTTP_PORT);
    exit(1);
}

