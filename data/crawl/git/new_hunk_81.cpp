		     int diagnose_misspelt_rev)
{
	if (*arg == '-')
		die(_("option '%s' must come before non-option arguments"), arg);
	if (looks_like_pathspec(arg) || check_filename(prefix, arg))
		return;
	die_verify_filename(prefix, arg, diagnose_misspelt_rev);
