	struct child_process cp;
	struct argv_array child_env = ARGV_ARRAY_INIT;
	int counter = 0, len, ret;
	unsigned char rev[20];

	if (file_exists(path) && !is_empty_dir(path))
		die(_("'%s' already exists"), path);

	name = worktree_basename(path, &len);
	strbuf_addstr(&sb_repo,
		      git_path("worktrees/%.*s", (int)(path + len - name), name));
