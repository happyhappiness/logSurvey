
static void read_rr(struct string_list *rr)
{
	struct strbuf buf = STRBUF_INIT;
	FILE *in = fopen(merge_rr_path, "r");

	if (!in)
		return;
	while (!strbuf_getwholeline(&buf, in, '\0')) {
		char *path;
		unsigned char sha1[20];

		/* There has to be the hash, tab, path and then NUL */
		if (buf.len < 42 || get_sha1_hex(buf.buf, sha1))
			die("corrupt MERGE_RR");

		if (buf.buf[40] != '\t')
			die("corrupt MERGE_RR");
		buf.buf[40] = '\0';
		path = buf.buf + 41;

		string_list_insert(rr, path)->util = xstrdup(buf.buf);
	}
	strbuf_release(&buf);
	fclose(in);
}
