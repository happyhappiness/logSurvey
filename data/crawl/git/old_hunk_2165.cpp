{
	if (git_config_set_multivar_in_file_gently(config_filename, key, value,
						   value_regex, multi_replace) < 0)
		die(_("Could not set '%s' to '%s'"), key, value);
}

int git_config_set_multivar_gently(const char *key, const char *value,
