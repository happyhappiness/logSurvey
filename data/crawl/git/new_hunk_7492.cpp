{
	if (!strcmp(var, "format.subjectprefix")) {
		if (!value)
			config_error_nonbool(var);
		fmt_patch_subject_prefix = xstrdup(value);
		return 0;
	}