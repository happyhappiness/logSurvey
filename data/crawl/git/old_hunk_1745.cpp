					 o->branch2, path2);

	if (mfi.clean && !df_conflict_remains &&
	    sha_eq(mfi.oid.hash, a_sha) && mfi.mode == a_mode) {
		int path_renamed_outside_HEAD;
		output(o, 3, _("Skipped %s (merged same as existing)"), path);
		/*
