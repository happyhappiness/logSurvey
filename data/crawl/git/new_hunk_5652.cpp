	if (!cmit)
		die("%s is not a valid '%s' object", arg, commit_type);

	n = cmit->util;
	if (n) {
		/*
