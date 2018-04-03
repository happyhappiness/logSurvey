		if (dir_in_way(path, !o->call_depth))
			df_conflict_remains = 1;
	}
	if (merge_file_special_markers(o, &one, &a, &b,
				       o->branch1, path1,
				       o->branch2, path2, &mfi))
		return -1;

	if (mfi.clean && !df_conflict_remains &&
	    oid_eq(&mfi.oid, a_oid) && mfi.mode == a_mode) {
		int path_renamed_outside_HEAD;
		output(o, 3, _("Skipped %s (merged same as existing)"), path);
		/*
