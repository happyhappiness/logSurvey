	return NULL;
}

static void check_linked_checkout(const char *branch, const char *id)
{
	struct strbuf sb = STRBUF_INIT;
	struct strbuf path = STRBUF_INIT;
	struct strbuf gitdir = STRBUF_INIT;

	/*
	 * $GIT_COMMON_DIR/HEAD is practically outside
	 * $GIT_DIR so resolve_ref_unsafe() won't work (it
	 * uses git_path). Parse the ref ourselves.
	 */
	if (id)
		strbuf_addf(&path, "%s/worktrees/%s/HEAD", get_git_common_dir(), id);
	else
		strbuf_addf(&path, "%s/HEAD", get_git_common_dir());

	if (!strbuf_readlink(&sb, path.buf, 0)) {
		if (!starts_with(sb.buf, "refs/") ||
		    check_refname_format(sb.buf, 0))
			goto done;
	} else if (strbuf_read_file(&sb, path.buf, 0) >= 0 &&
	    starts_with(sb.buf, "ref:")) {
		strbuf_remove(&sb, 0, strlen("ref:"));
		strbuf_trim(&sb);
	} else
		goto done;
	if (strcmp(sb.buf, branch))
		goto done;
	if (id) {
		strbuf_reset(&path);
		strbuf_addf(&path, "%s/worktrees/%s/gitdir", get_git_common_dir(), id);
		if (strbuf_read_file(&gitdir, path.buf, 0) <= 0)
			goto done;
		strbuf_rtrim(&gitdir);
	} else
		strbuf_addstr(&gitdir, get_git_common_dir());
	skip_prefix(branch, "refs/heads/", &branch);
	strbuf_strip_suffix(&gitdir, ".git");
	die(_("'%s' is already checked out at '%s'"), branch, gitdir.buf);
done:
	strbuf_release(&path);
	strbuf_release(&sb);
	strbuf_release(&gitdir);
}

static void die_if_checked_out(const char *branch)
{
	struct strbuf path = STRBUF_INIT;
	DIR *dir;
	struct dirent *d;

	check_linked_checkout(branch, NULL);

	strbuf_addf(&path, "%s/worktrees", get_git_common_dir());
	dir = opendir(path.buf);
	strbuf_release(&path);
	if (!dir)
		return;

	while ((d = readdir(dir)) != NULL) {
		if (!strcmp(d->d_name, ".") || !strcmp(d->d_name, ".."))
			continue;
		check_linked_checkout(branch, d->d_name);
	}
	closedir(dir);
}

static int parse_branchname_arg(int argc, const char **argv,
				int dwim_new_local_branch_ok,
				struct branch_info *new,