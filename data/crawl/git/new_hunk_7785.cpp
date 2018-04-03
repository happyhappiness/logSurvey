		return 0;
	}

	if (!strcmp(var, "core.excludesfile")) {
		if (!value)
			die("core.excludesfile without value");
		excludes_file = xstrdup(value);
		return 0;
	}

	/* Add other config variables here and to Documentation/config.txt. */
	return 0;
}
