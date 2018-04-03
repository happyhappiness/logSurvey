	if (ignored && ignored_only)
		die(_("-x and -X cannot be used together"));

	if (!show_only && !force) {
		if (config_set)
			die(_("clean.requireForce set to true and neither -n nor -f given; "
				  "refusing to clean"));
