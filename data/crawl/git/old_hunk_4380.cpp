		 !(right = lookup_commit_reference(two)))
		message = "(commits not present)";

	if (!message) {
		init_revisions(&rev, NULL);
		setup_revisions(0, NULL, &rev, NULL);
		rev.left_right = 1;
		rev.first_parent_only = 1;
		left->object.flags |= SYMMETRIC_LEFT;
		add_pending_object(&rev, &left->object, path);
		add_pending_object(&rev, &right->object, path);
		merge_bases = get_merge_bases(left, right, 1);
		if (merge_bases) {
			if (merge_bases->item == left)
				fast_forward = 1;
			else if (merge_bases->item == right)
				fast_backward = 1;
		}
		for (list = merge_bases; list; list = list->next) {
			list->item->object.flags |= UNINTERESTING;
			add_pending_object(&rev, &list->item->object,
				sha1_to_hex(list->item->object.sha1));
		}
		if (prepare_revision_walk(&rev))
			message = "(revision walker failed)";
	}

	if (dirty_submodule & DIRTY_SUBMODULE_UNTRACKED)
		fprintf(f, "Submodule %s contains untracked content\n", path);
