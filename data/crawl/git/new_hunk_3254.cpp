		st_stdin.st_mode == st_stdout.st_mode);
}

static struct commit_list *reduce_parents(struct commit *head_commit,
					  int *head_subsumed,
					  struct commit_list *remoteheads)
{
	struct commit_list *parents, *next, **remotes = &remoteheads;

	/*
	 * Is the current HEAD reachable from another commit being
