		if (!do_for_each_entry_in_dir(dir, 0, nonmatching_ref_fn, &data))
			return 1;

		report_refname_conflict(data.found, refname);
		return 0;
	}
