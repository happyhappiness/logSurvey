	}

	if (!strcmp(var, "core.pager")) {
		pager_program = xstrdup(value);
		return 0;
	}

	if (!strcmp(var, "core.editor")) {
		editor_program = xstrdup(value);
		return 0;
	}

	if (!strcmp(var, "core.excludesfile")) {
		if (!value)
			die("core.excludesfile without value");
		excludes_file = xstrdup(value);
		return 0;
	}

	if (!strcmp(var, "core.whitespace")) {
		whitespace_rule_cfg = parse_whitespace_rule(value);
		return 0;
	}