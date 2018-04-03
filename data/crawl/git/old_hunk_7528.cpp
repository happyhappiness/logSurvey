		 * that represents the "current" state for merge-recursive
		 * to work on.
		 */
		if (write_tree(head, 0, NULL))
			die ("Your index file is unmerged.");
	} else {
		struct wt_status s;
