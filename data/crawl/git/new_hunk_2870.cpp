	}
	ref_transaction_free(transaction);

	unlink(git_path_cherry_pick_head());
	unlink(git_path_revert_head());
	unlink(git_path_merge_head());
	unlink(git_path_merge_msg());
	unlink(git_path_merge_mode());
	unlink(git_path_squash_msg());

	if (commit_index_files())
		die (_("Repository has been updated, but unable to write\n"
