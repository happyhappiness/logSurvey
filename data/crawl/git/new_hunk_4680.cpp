	if (strbuf_read_file(&sb, git_path(commit_editmsg), 0) < 0) {
		int saved_errno = errno;
		rollback_index_files();
		die(_("could not read commit message: %s"), strerror(saved_errno));
	}

	/* Truncate the message just before the diff, if any. */
