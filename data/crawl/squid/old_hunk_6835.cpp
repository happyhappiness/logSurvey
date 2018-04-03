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
