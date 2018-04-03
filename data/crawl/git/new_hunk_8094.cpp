#include "cache.h"
#include "refs.h"
#include "commit.h"
#include "strbuf.h"

static char *get_stdin(void)
{
	struct strbuf buf;
	strbuf_init(&buf, 0);
	if (strbuf_read(&buf, 0, 1024) < 0) {
		die("error reading standard input: %s", strerror(errno));
	}
	return strbuf_detach(&buf);
}

static void show_new(enum object_type type, unsigned char *sha1_new)