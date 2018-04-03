#include "cache.h"
#include "quote.h"

/* Stolen from "imap-send.c". */
int nfvasprintf(char **strp, const char *fmt, va_list ap)
{
	int len;
	char tmp[1024];

	if ((len = vsnprintf(tmp, sizeof(tmp), fmt, ap)) < 0 ||
	    !(*strp = xmalloc(len + 1)))
		die("Fatal: Out of memory\n");
	if (len >= (int)sizeof(tmp))
		vsprintf(*strp, fmt, ap);
	else
		memcpy(*strp, tmp, len + 1);
	return len;
}

int nfasprintf(char **str, const char *fmt, ...)
{
	int rc;
	va_list args;

	va_start(args, fmt);
	rc = nfvasprintf(str, fmt, args);
	va_end(args);
	return rc;
}

/* Get a trace file descriptor from GIT_TRACE env variable. */
static int get_trace_fd(int *need_close)
{
