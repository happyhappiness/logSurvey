		check_argc(argc, 0, 0);
		if (git_config(show_all_config, NULL) < 0) {
			if (config_exclusive_filename)
				die("unable to read config file %s: %s",
				    config_exclusive_filename, strerror(errno));
			else
				die("error processing config file(s)");
		}
