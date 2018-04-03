		struct commit *filter;
		filter = lookup_commit_reference_gently(merge_filter_ref, 0);
		if (!filter)
			die(_("object '%s' does not point to a commit"),
			    sha1_to_hex(merge_filter_ref));

		filter->object.flags |= UNINTERESTING;
