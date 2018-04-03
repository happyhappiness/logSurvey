	regcomp \
	regexec \
	regfree \
	setrlimit \
	strdup \
	strerror \
	sysconf \
	syslog \
	timegm\
)

dnl Need the debugging version of malloc if available
XTRA_OBJS=''
if test "$HAVE_LIBMALLOC" = "yes" ; then
