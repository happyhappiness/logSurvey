#define DEBUGP_C(x, args...)
#endif

#ifdef DEBUG
#define debug(x, args...)	fprintf(stderr, x, ## args)
#else
#define debug(x, args...)
#endif

static int sockfd = -1;
