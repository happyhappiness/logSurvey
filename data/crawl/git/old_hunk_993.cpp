	 * are pretty certain that it is syntactically correct.
	 */
	if (git_config_from_file(populate_opts_cb, git_path_opts_file(), opts) < 0)
		return error(_("Malformed options sheet: %s"),
			git_path_opts_file());
	return 0;
}
