		const struct object_id *mb = &result->item->object.oid;
		if (!oidcmp(mb, current_bad_oid)) {
			handle_bad_merge_base();
		} else if (0 <= sha1_array_lookup(&good_revs, mb)) {
			continue;
		} else if (0 <= sha1_array_lookup(&skipped_revs, mb)) {
			handle_skipped_merge_base(mb);
		} else {
			printf(_("Bisecting: a merge base must be tested\n"));
