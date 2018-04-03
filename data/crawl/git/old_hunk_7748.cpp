
	/* Get the commit message and validate it */
	header_len = sb.len;
	if (!no_edit) {
		fprintf(stderr, "launching editor, log %s\n", logfile);
		launch_editor(git_path(commit_editmsg), &sb);
	} else if (strbuf_read_file(&sb, git_path(commit_editmsg), 0) < 0)
		die("could not read commit message\n");
	if (run_hook(index_file, "commit-msg", commit_editmsg))
		exit(1);