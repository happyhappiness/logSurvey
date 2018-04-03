	unsigned processed:1;
};

static struct path_list current_file_set = {NULL, 0, 0, 1};
static struct path_list current_directory_set = {NULL, 0, 0, 1};

static int call_depth = 0;
static int verbosity = 2;
static int buffer_output = 1;
static struct strbuf obuf = STRBUF_INIT;

static int show(int v)
{
	return (!call_depth && verbosity >= v) || verbosity >= 5;
}

static void flush_output(void)
{
	if (obuf.len) {
		fputs(obuf.buf, stdout);
		strbuf_reset(&obuf);
	}
}

static void output(int v, const char *fmt, ...)
{
	int len;
	va_list ap;

	if (!show(v))
		return;

	strbuf_grow(&obuf, call_depth * 2 + 2);
	memset(obuf.buf + obuf.len, ' ', call_depth * 2);
	strbuf_setlen(&obuf, obuf.len + call_depth * 2);

	va_start(ap, fmt);
	len = vsnprintf(obuf.buf + obuf.len, strbuf_avail(&obuf), fmt, ap);
	va_end(ap);

	if (len < 0)
		len = 0;
	if (len >= strbuf_avail(&obuf)) {
		strbuf_grow(&obuf, len + 2);
		va_start(ap, fmt);
		len = vsnprintf(obuf.buf + obuf.len, strbuf_avail(&obuf), fmt, ap);
		va_end(ap);
		if (len >= strbuf_avail(&obuf)) {
			die("this should not happen, your snprintf is broken");
		}
	}
	strbuf_setlen(&obuf, obuf.len + len);
	strbuf_add(&obuf, "\n", 1);
	if (!buffer_output)
		flush_output();
}

static void output_commit_title(struct commit *commit)
