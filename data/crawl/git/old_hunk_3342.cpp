		return 0;

	matched_src = matched_dst = NULL;
	switch (count_refspec_match(rs->src, src, &matched_src)) {
	case 1:
		copy_src = 1;
		break;
	case 0:
		/* The source could be in the get_sha1() format
		 * not a reference name.  :refs/other is a
		 * way to delete 'other' ref at the remote end.
		 */
		matched_src = try_explicit_object_name(rs->src);
		if (!matched_src)
			return error("src refspec %s does not match any.", rs->src);
		copy_src = 0;
		break;
	default:
		return error("src refspec %s matches more than one.", rs->src);
	}

	if (!dst_value) {
		unsigned char sha1[20];
