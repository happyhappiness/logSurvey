		errs = 1;

	if (!dst_value) {
		unsigned char sha1[20];
		int flag;

		if (!matched_src)
			return errs;
		dst_value = resolve_ref(matched_src->name, sha1, 1, &flag);
		if (!dst_value ||
		    ((flag & REF_ISSYMREF) &&
		     prefixcmp(dst_value, "refs/heads/")))
			die("%s cannot be resolved to branch.",
			    matched_src->name);
	}

	switch (count_refspec_match(dst_value, dst, &matched_dst)) {
