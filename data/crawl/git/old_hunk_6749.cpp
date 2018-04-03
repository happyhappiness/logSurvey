	if (!show(o, v))
		return;

	strbuf_grow(&obuf, o->call_depth * 2 + 2);
	memset(obuf.buf + obuf.len, ' ', o->call_depth * 2);
	strbuf_setlen(&obuf, obuf.len + o->call_depth * 2);

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
	if (!o->buffer_output)
		flush_output();
}

static void output_commit_title(struct merge_options *o, struct commit *commit)
{
	int i;
	flush_output();
	for (i = o->call_depth; i--;)
		fputs("  ", stdout);
	if (commit->util)
