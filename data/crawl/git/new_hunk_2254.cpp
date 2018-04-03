
	strbuf_reset(&buf);
	strbuf_addf(&buf, "remote.%s.fetch", rename.new);
	git_config_set_multivar_or_die(buf.buf, NULL, NULL, 1);
	strbuf_addf(&old_remote_context, ":refs/remotes/%s/", rename.old);
	for (i = 0; i < oldremote->fetch_refspec_nr; i++) {
		char *ptr;
