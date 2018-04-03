
}

void git_config_set_multivar_in_file_or_die(const char *config_filename,
				const char *key, const char *value,
				const char *value_regex, int multi_replace)
{
	if (git_config_set_multivar_in_file(config_filename, key, value,
					    value_regex, multi_replace) < 0)
		die(_("Could not set '%s' to '%s'"), key, value);
}

int git_config_set_multivar(const char *key, const char *value,
			const char *value_regex, int multi_replace)
{
	return git_config_set_multivar_in_file(NULL, key, value, value_regex,
					       multi_replace);
}

void git_config_set_multivar_or_die(const char *key, const char *value,
			const char *value_regex, int multi_replace)
{
	git_config_set_multivar_in_file_or_die(NULL, key, value, value_regex,
					       multi_replace);
}

static int section_name_match (const char *buf, const char *name)
{
	int i = 0, j = 0, dot = 0;