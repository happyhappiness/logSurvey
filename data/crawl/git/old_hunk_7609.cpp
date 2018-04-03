	if (deny_non_fast_forwards && !is_null_sha1(new_sha1) &&
	    !is_null_sha1(old_sha1) &&
	    !prefixcmp(name, "refs/heads/")) {
		struct commit *old_commit, *new_commit;
		struct commit_list *bases, *ent;

		old_commit = (struct commit *)parse_object(old_sha1);
		new_commit = (struct commit *)parse_object(new_sha1);
		bases = get_merge_bases(old_commit, new_commit, 1);
		for (ent = bases; ent; ent = ent->next)
			if (!hashcmp(old_sha1, ent->item->object.sha1))