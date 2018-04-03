
	new_len = got->len;
	if (!strip_suffix_mem(got->buf, &new_len, tail))
		return 0; /* insane redirect scheme */

	strbuf_reset(base);
	strbuf_add(base, got->buf, new_len);
	return 1;
}

