		strbuf_addf(&sb, "encoding %s\n", git_commit_encoding);
	strbuf_addch(&sb, '\n');

	/* Get the commit message and validate it */
	header_len = sb.len;
	if (use_editor) {
		char index[PATH_MAX];
		const char *env[2] = { index, NULL };
		snprintf(index, sizeof(index), "GIT_INDEX_FILE=%s", index_file);
		launch_editor(git_path(commit_editmsg), NULL, env);
	}
	if (!no_verify &&
	    run_hook(index_file, "commit-msg", git_path(commit_editmsg), NULL)) {
		rollback_index_files();
		exit(1);
	}
	if (strbuf_read_file(&sb, git_path(commit_editmsg), 0) < 0) {
		rollback_index_files();
		die("could not read commit message");
