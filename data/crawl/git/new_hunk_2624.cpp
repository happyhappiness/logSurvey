	else if (contents_from)
		die("Cannot use --contents with final commit object name");

	if (reverse && revs.first_parent_only) {
		struct object_array_entry *entry = find_single_final(sb.revs);
		if (!entry)
			die("--reverse and --first-parent together require specified latest commit");
		else
			final_commit = (struct commit*) entry->item;
	}

	/*
	 * If we have bottom, this will mark the ancestors of the
	 * bottom commits we would reach while traversing as
