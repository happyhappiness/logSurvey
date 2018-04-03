
static int git_log_config(const char *var, const char *value)
{
	if (!strcmp(var, "format.subjectprefix")) {
		if (!value)
			die("format.subjectprefix without value");
		fmt_patch_subject_prefix = xstrdup(value);
		return 0;
	}
	if (!strcmp(var, "log.showroot")) {
		default_show_root = git_config_bool(var, value);
		return 0;
