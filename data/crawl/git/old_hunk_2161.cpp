				     const char *key, const char *value,
				     const char *value_regex, int multi_replace)
{
	if (git_config_set_multivar_in_file_gently(config_filename, key, value,
						   value_regex, multi_replace))
		die(_("could not set '%s' to '%s'"), key, value);
}

int git_config_set_multivar_gently(const char *key, const char *value,