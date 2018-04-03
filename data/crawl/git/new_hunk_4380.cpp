		 !(right = lookup_commit_reference(two)))
		message = "(commits not present)";

	if (!message &&
	    prepare_submodule_summary(&rev, path, left, right,
					&fast_forward, &fast_backward))
		message = "(revision walker failed)";

	if (dirty_submodule & DIRTY_SUBMODULE_UNTRACKED)
		fprintf(f, "Submodule %s contains untracked content\n", path);
