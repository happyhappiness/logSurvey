				sha1_to_hex(j->item->object.sha1));
		fd = open(git_path("MERGE_HEAD"), O_WRONLY | O_CREAT, 0666);
		if (fd < 0)
			die_errno(_("Could not open '%s' for writing"),
				  git_path("MERGE_HEAD"));
		if (write_in_full(fd, buf.buf, buf.len) != buf.len)
			die_errno(_("Could not write to '%s'"), git_path("MERGE_HEAD"));
		close(fd);
		strbuf_addch(&merge_msg, '\n');
		fd = open(git_path("MERGE_MSG"), O_WRONLY | O_CREAT, 0666);
		if (fd < 0)
			die_errno(_("Could not open '%s' for writing"),
				  git_path("MERGE_MSG"));
		if (write_in_full(fd, merge_msg.buf, merge_msg.len) !=
			merge_msg.len)
			die_errno(_("Could not write to '%s'"), git_path("MERGE_MSG"));
		close(fd);
		fd = open(git_path("MERGE_MODE"), O_WRONLY | O_CREAT | O_TRUNC, 0666);
		if (fd < 0)
			die_errno(_("Could not open '%s' for writing"),
				  git_path("MERGE_MODE"));
		strbuf_reset(&buf);
		if (!allow_fast_forward)
			strbuf_addf(&buf, "no-ff");
		if (write_in_full(fd, buf.buf, buf.len) != buf.len)
			die_errno(_("Could not write to '%s'"), git_path("MERGE_MODE"));
		close(fd);
	}

	if (merge_was_ok) {
		fprintf(stderr, _("Automatic merge went well; "
			"stopped before committing as requested\n"));
		return 0;
	} else
		return suggest_conflicts(option_renormalize);
