	}

	if (!strcmp(var, "core.abbrev")) {
		int abbrev = git_config_int(var, value);
		if (abbrev < minimum_abbrev || abbrev > 40)
			return -1;
		default_abbrev = abbrev;
		return 0;
	}
