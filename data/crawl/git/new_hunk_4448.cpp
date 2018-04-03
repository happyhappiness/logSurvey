		dir.flags |= DIR_SHOW_IGNORED;

	if (ignored && ignored_only)
		die(_("-x and -X cannot be used together"));

	if (!show_only && !force)
		die("clean.requireForce %s to true and neither -n nor -f given; "
