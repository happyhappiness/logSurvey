
	real_ref = NULL;
	if (get_sha1(start_name, sha1)) {
		if (explicit_tracking)
			die(_(upstream_missing), start_name);
		die("Not a valid object name: '%s'.", start_name);
	}
