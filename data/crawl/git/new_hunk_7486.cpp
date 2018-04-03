	}

	if (!strcmp(var, "core.pager")) {
		if (!value)
			return config_error_nonbool(var);
		pager_program = xstrdup(value);
		return 0;
	}

	if (!strcmp(var, "core.editor")) {
		if (!value)
			return config_error_nonbool(var);
		editor_program = xstrdup(value);
		return 0;
	}

	if (!strcmp(var, "core.excludesfile")) {
		if (!value)
			return config_error_nonbool(var);
		excludes_file = xstrdup(value);
		return 0;
	}

	if (!strcmp(var, "core.whitespace")) {
		if (!value)
			return config_error_nonbool(var);
		whitespace_rule_cfg = parse_whitespace_rule(value);
		return 0;
	}