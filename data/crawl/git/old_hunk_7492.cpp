{
	if (!strcmp(var, "format.subjectprefix")) {
		if (!value)
			die("format.subjectprefix without value");
		fmt_patch_subject_prefix = xstrdup(value);
		return 0;
	}