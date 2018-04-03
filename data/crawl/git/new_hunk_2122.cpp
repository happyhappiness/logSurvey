
void die_if_checked_out(const char *branch)
{
	const struct worktree *wt;

	wt = find_shared_symref("HEAD", branch);
	if (!wt)
		return;
	skip_prefix(branch, "refs/heads/", &branch);
	die(_("'%s' is already checked out at '%s'"),
	    branch, wt->path);
}

int replace_each_worktree_head_symref(const char *oldref, const char *newref)
