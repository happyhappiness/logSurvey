		} else if (!strcmp(arg, "-h")) {
			usage(builtin_log_usage);
		} else
			die(_("unrecognized argument: %s"), arg);
	}

	/*
