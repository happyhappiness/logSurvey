	free(s);
}

static const char *get_upstream_branch(const char *branch_buf, int len)
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
				   int at, struct strbuf *buf)
{
	int len;

	len = upstream_mark(name + at, namelen - at);
	if (!len)
		return -1;

	if (memchr(name, ':', at))
		return -1;

	set_shortened_ref(buf, get_upstream_branch(name, at));
	return len + at;
}

