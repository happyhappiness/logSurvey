		return 0;
	}

	if (!strcmp(var, "core.unreliablehardlinks")) {
		unreliable_hardlinks = git_config_bool(var, value);
		return 0;
	}

