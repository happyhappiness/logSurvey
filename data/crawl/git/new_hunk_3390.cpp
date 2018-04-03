	if (len > 0)
		return reinterpret(name, namelen, len, buf);

	len = interpret_upstream_mark(name, namelen, cp - name, buf);
	if (len > 0)
		return len;

	return -1;
}

int strbuf_branchname(struct strbuf *sb, const char *name)