	if (argc != 3)
		usage_with_options(builtin_remote_rename_usage, options);

	rename.old = argv[1];
	rename.new = argv[2];
	rename.remote_branches = &remote_branches;

	oldremote = remote_get(rename.old);
	if (!remote_is_configured(oldremote, 1))
		die(_("No such remote: %s"), rename.old);

	if (!strcmp(rename.old, rename.new) && oldremote->origin != REMOTE_CONFIG)
		return migrate_file(oldremote);

	newremote = remote_get(rename.new);
	if (remote_is_configured(newremote, 1))
		die(_("remote %s already exists."), rename.new);

	strbuf_addf(&buf, "refs/heads/test:refs/remotes/%s/test", rename.new);
	if (!valid_fetch_refspec(buf.buf))
		die(_("'%s' is not a valid remote name"), rename.new);

	strbuf_reset(&buf);
	strbuf_addf(&buf, "remote.%s", rename.old);
	strbuf_addf(&buf2, "remote.%s", rename.new);
	if (git_config_rename_section(buf.buf, buf2.buf) < 1)
		return error(_("Could not rename config section '%s' to '%s'"),
				buf.buf, buf2.buf);

	strbuf_reset(&buf);
	strbuf_addf(&buf, "remote.%s.fetch", rename.new);
	git_config_set_multivar(buf.buf, NULL, NULL, 1);
	strbuf_addf(&old_remote_context, ":refs/remotes/%s/", rename.old);
	for (i = 0; i < oldremote->fetch_refspec_nr; i++) {
		char *ptr;

