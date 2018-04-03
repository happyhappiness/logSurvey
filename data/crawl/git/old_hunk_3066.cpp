		free(head_ref);
	}

	if (opts->new_worktree)
		return prepare_linked_checkout(opts, new);

	if (!new->commit && opts->new_branch) {
		unsigned char rev[20];