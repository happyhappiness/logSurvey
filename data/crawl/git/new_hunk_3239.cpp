		if (!do_for_each_entry_in_dir(dir, 0, nonmatching_ref_fn, &data))
			return 1;

		error("'%s' exists; cannot create '%s'",
		      data.conflicting_refname, refname);
		return 0;
	}
