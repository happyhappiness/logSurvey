	if ((head_rev != reference_rev) &&
	    in_merge_bases(rev, &head_rev, 1) != merged) {
		if (merged)
			warning("deleting branch '%s' that has been merged to\n"
				"         '%s', but it is not yet merged to HEAD.",
				name, reference_name);
		else
			warning("not deleting branch '%s' that is not yet merged to\n"
				"         '%s', even though it is merged to HEAD.",
				name, reference_name);
	}
	return merged;
