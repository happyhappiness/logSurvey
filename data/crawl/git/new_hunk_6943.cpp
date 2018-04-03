		branch.item = lookup_commit_reference_gently(sha1, 1);
		if (!branch.item)
			die("Unable to lookup tip of branch %s", refname);
		add_pending_object(&ref_list->revs,
				   (struct object *)branch.item, refname);
	}

	/* Resize buffer */
