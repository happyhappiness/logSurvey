#include "dir.h"
#include "submodule.h"

static void flush_output(struct merge_options *o)
{
	if (o->obuf.len) {
		fputs(o->obuf.buf, stdout);
		strbuf_reset(&o->obuf);
	}
}

static int err(struct merge_options *o, const char *err, ...)
{
	va_list params;

	flush_output(o);
	va_start(params, err);
	strbuf_vaddf(&o->obuf, err, params);
	va_end(params);
	error("%s", o->obuf.buf);
	strbuf_reset(&o->obuf);

	return -1;
}

static struct tree *shift_tree_object(struct tree *one, struct tree *two,
				      const char *subtree_shift)
{
