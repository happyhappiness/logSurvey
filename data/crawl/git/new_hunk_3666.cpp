		trust_ctime = git_config_bool(var, value);
		return 0;
	}
	if (!strcmp(var, "core.statinfo") ||
	    !strcmp(var, "core.checkstat")) {
		/*
		 * NEEDSWORK: statinfo was a typo in v1.8.2 that has
		 * never been advertised.  we will remove it at Git
		 * 2.0 boundary.
		 */
		if (!strcmp(var, "core.statinfo")) {
			static int warned;
			if (!warned++) {
				warning("'core.statinfo' will be removed in Git 2.0; "
					"use 'core.checkstat' instead.");
			}
		}
		if (!strcasecmp(value, "default"))
			check_stat = 1;
		else if (!strcasecmp(value, "minimal"))