		die(_("'%s' is not a valid remote name"), name);

	strbuf_addf(&buf, "remote.%s.url", name);
	if (git_config_set(buf.buf, url))
		return 1;

	if (!mirror || mirror & MIRROR_FETCH) {
		strbuf_reset(&buf);
