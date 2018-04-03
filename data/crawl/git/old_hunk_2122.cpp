
void die_if_checked_out(const char *branch)
{
	char *existing;

	existing = find_shared_symref("HEAD", branch);
	if (existing) {
		skip_prefix(branch, "refs/heads/", &branch);
		die(_("'%s' is already checked out at '%s'"), branch, existing);
	}
}

int replace_each_worktree_head_symref(const char *oldref, const char *newref)
