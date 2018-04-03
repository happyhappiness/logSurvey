		die("clean.requireForce%s set and -n or -f not given; "
		    "refusing to clean", config_set ? "" : " not");

	dir.flags |= DIR_SHOW_OTHER_DIRECTORIES;

	if (!ignored)
		setup_standard_excludes(&dir);
