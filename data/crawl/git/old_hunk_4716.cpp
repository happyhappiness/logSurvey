	if (!arg)
		arg = "HEAD";
	if (get_sha1(arg, merge_filter_ref))
		die("malformed object name %s", arg);
	return 0;
}

