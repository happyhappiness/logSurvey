		strbuf_addf(&sb, "encoding %s\n", git_commit_encoding);
	strbuf_addch(&sb, '\n');

	/* Finally, get the commit message */
	header_len = sb.len;
	if (strbuf_read_file(&sb, git_path(commit_editmsg), 0) < 0) {
		rollback_index_files();
		die("could not read commit message");
