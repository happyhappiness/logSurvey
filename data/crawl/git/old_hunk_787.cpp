				      const char *path,
				      unsigned flags)
{
	const char *sub_git_dir, *v;
	char *real_sub_git_dir = NULL, *real_common_git_dir = NULL;
	struct strbuf gitdir = STRBUF_INIT;

	strbuf_addf(&gitdir, "%s/.git", path);
	sub_git_dir = resolve_gitdir(gitdir.buf);

	/* Not populated? */
	if (!sub_git_dir)
		goto out;

	/* Is it already absorbed into the superprojects git dir? */
	real_sub_git_dir = real_pathdup(sub_git_dir);
	real_common_git_dir = real_pathdup(get_git_common_dir());
	if (!skip_prefix(real_sub_git_dir, real_common_git_dir, &v))
		relocate_single_git_dir_into_superproject(prefix, path);

	if (flags & ABSORB_GITDIR_RECURSE_SUBMODULES) {
		struct child_process cp = CHILD_PROCESS_INIT;
