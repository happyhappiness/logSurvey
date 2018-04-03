					 o->branch2, path2);

	if (mfi.clean && !df_conflict_remains &&
	    oid_eq(&mfi.oid, a_oid) && mfi.mode == a_mode) {
		int path_renamed_outside_HEAD;
		output(o, 3, _("Skipped %s (merged same as existing)"), path);
		/*
