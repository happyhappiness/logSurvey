		errs = 1;

	if (!dst_value) {
		if (!matched_src)
			return errs;
		dst_value = matched_src->name;
	}

	switch (count_refspec_match(dst_value, dst, &matched_dst)) {
