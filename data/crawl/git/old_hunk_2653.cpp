	return add_worktree(path, branch, &opts);
}

int cmd_worktree(int ac, const char **av, const char *prefix)
{
	struct option options[] = {
