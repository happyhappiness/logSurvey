	if (!opt->message_given && !buf->len)
		die(_("no tag message?"));

	strbuf_insert(buf, 0, header_buf, header_len);

	if (build_tag_object(buf, opt->sign, result) < 0) {
		if (path)