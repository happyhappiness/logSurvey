{
	char *branch = xstrndup(branch_buf, len);
	struct branch *upstream = branch_get(*branch ? branch : NULL);
	struct strbuf err = STRBUF_INIT;
	const char *ret;

	free(branch);

	ret = branch_get_upstream(upstream, &err);
	if (!ret)
		die("%s", err.buf);

	return ret;
}

static int interpret_upstream_mark(const char *name, int namelen,
