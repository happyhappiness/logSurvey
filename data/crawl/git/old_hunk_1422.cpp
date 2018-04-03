		if (dir_in_way(path, !o->call_depth))
			df_conflict_remains = 1;
	}
	mfi = merge_file_special_markers(o, &one, &a, &b,
					 o->branch1, path1,
					 o->branch2, path2);

	if (mfi.clean && !df_conflict_remains &&
	    sha_eq(mfi.sha, a_sha) && mfi.mode == a_mode) {
		int path_renamed_outside_HEAD;
		output(o, 3, _("Skipped %s (merged same as existing)"), path);
		/*
