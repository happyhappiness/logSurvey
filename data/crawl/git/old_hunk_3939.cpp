		if (fd < 0)
			die_errno(_("could not create file '%s'"), path);

		if (!is_null_sha1(prev))
			write_tag_body(fd, prev);
		else if (opt->cleanup_mode == CLEANUP_ALL)
			write_or_die(fd, _(tag_template),
					strlen(_(tag_template)));
		else
			write_or_die(fd, _(tag_template_nocleanup),
					strlen(_(tag_template_nocleanup)));
		close(fd);

		if (launch_editor(path, buf, NULL)) {
