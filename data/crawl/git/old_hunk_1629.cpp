	return (!o->call_depth && o->verbosity >= v) || o->verbosity >= 5;
}

static void flush_output(struct merge_options *o)
{
	if (o->obuf.len) {
		fputs(o->obuf.buf, stdout);
		strbuf_reset(&o->obuf);
	}
}

__attribute__((format (printf, 3, 4)))
static void output(struct merge_options *o, int v, const char *fmt, ...)
{
