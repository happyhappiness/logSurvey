{
	if (*arg == '-')
		die("bad flag '%s' used after filename", arg);
	if (check_filename(prefix, arg) || looks_like_pathspec(arg))
		return;
	die_verify_filename(prefix, arg, diagnose_misspelt_rev);
}
