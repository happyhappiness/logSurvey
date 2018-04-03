	struct strbuf gitdir = STRBUF_INIT;
	char *existing = NULL;

	if (!id)
		die("Missing linked worktree name");

	strbuf_addf(&path, "%s/worktrees/%s/%s", get_git_common_dir(), id, symref);

	if (parse_ref(path.buf, &sb, NULL) < 0)
		goto done;
	if (strcmp(sb.buf, branch))
		goto done;
	strbuf_reset(&path);
	strbuf_addf(&path, "%s/worktrees/%s/gitdir", get_git_common_dir(), id);
	if (strbuf_read_file(&gitdir, path.buf, 0) <= 0)
		goto done;
	strbuf_rtrim(&gitdir);
	strbuf_strip_suffix(&gitdir, ".git");

	existing = strbuf_detach(&gitdir, NULL);
