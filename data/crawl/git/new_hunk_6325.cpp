				return 0;
	}
	if (MAX_REVS <= ref_name_cnt) {
		warning("ignoring %s; cannot handle more than %d refs",
			refname, MAX_REVS);
		return 0;
	}