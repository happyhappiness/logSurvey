		struct object_entry *commit_oe = find_mark(commit_mark);
		if (commit_oe->type != OBJ_COMMIT)
			die("Mark :%" PRIuMAX " not a commit", commit_mark);
		hashcpy(commit_oid.hash, commit_oe->idx.sha1);
	} else if (!get_oid(p, &commit_oid)) {
		unsigned long size;
		char *buf = read_object_with_reference(commit_oid.hash,
