		die(_("'%s' is not a valid remote name"), name);

	strbuf_addf(&buf, "remote.%s.url", name);
	git_config_set_or_die(buf.buf, url);

	if (!mirror || mirror & MIRROR_FETCH) {
		strbuf_reset(&buf);
