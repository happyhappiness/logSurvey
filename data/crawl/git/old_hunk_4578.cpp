		if (allow_trivial && !fast_forward_only) {
			/* See if it is really trivial. */
			git_committer_info(IDENT_ERROR_ON_NO_NAME);
			printf("Trying really trivial in-index merge...\n");
			if (!read_tree_trivial(common->item->object.sha1,
					head, remoteheads->item->object.sha1))
				return merge_trivial();
			printf("Nope.\n");
		}
	} else {
		/*
