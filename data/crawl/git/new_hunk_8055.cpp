#include "refs.h"
#include "strbuf.h"

static unsigned char current_commit_sha1[20];

void walker_say(struct walker *walker, const char *fmt, const char *hex)
{
	if (walker->get_verbosely)
		fprintf(stderr, fmt, hex);
}

