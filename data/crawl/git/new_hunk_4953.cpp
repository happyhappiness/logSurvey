		goto found_result;
	}

	result = merge_from_diffs(o, base_tree_sha1, local->tree->object.sha1,
				  remote->tree->object.sha1, local_tree);

	if (result > 0) { /* successful non-trivial merge */
		/* Commit result */
		struct commit_list *parents = NULL;
		commit_list_insert(remote, &parents); /* LIFO order */
		commit_list_insert(local, &parents);
		create_notes_commit(local_tree, parents, o->commit_msg,
				    result_sha1);
	}

found_result:
	free_commit_list(bases);
