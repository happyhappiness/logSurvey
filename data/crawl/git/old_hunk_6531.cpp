#include "refs.h"
#include "utf8.h"
#include "strbuf.h"

static int initialized;

void get_commit_notes(const struct commit *commit, struct strbuf *sb,
		const char *output_encoding)
{
	static const char *utf8 = "utf-8";
	struct strbuf name = STRBUF_INIT;
	const char *hex;
	unsigned char sha1[20];
	char *msg;
	unsigned long msgoffset, msglen;
	enum object_type type;
