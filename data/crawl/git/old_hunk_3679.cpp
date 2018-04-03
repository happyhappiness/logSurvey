	data.conflicting_refname = NULL;

	sort_ref_dir(dir);
	if (do_for_each_ref_in_dir(dir, 0, "", name_conflict_fn,
				   0, DO_FOR_EACH_INCLUDE_BROKEN,
				   &data)) {
		error("'%s' exists; cannot create '%s'",
		      data.conflicting_refname, refname);
		return 0;
