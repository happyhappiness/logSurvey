static struct string_list current_file_set = {NULL, 0, 0, 1};
static struct string_list current_directory_set = {NULL, 0, 0, 1};

static struct strbuf obuf = STRBUF_INIT;

static int show(struct merge_options *o, int v)
{
	return (!o->call_depth && o->verbosity >= v) || o->verbosity >= 5;
}

static void flush_output(void)
{
	if (obuf.len) {
		fputs(obuf.buf, stdout);
		strbuf_reset(&obuf);
	}
}

