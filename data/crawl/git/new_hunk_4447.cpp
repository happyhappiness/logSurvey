	if (ignored && ignored_only)
		die(_("-x and -X cannot be used together"));

	if (!show_only && !force) {
		if (config_set)
			die(_("clean.requireForce set to true and neither -n nor -f given; "
				  "refusing to clean"));
		else
			die(_("clean.requireForce defaults to true and neither -n nor -f given; "
				  "refusing to clean"));
	}

	if (force > 1)
		rm_flags = 0;