	if (ignored && ignored_only)
		die(_("-x and -X cannot be used together"));

	if (!show_only && !force)
		die("clean.requireForce %s to true and neither -n nor -f given; "
		    "refusing to clean", config_set ? "set" : "defaults");

	if (force > 1)
		rm_flags = 0;