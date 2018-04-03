	char *user_config = expand_user_path("~/.gitconfig");
	char *repo_config = git_pathdup("config");

	if (git_config_system() && !access_or_die(git_etc_gitconfig(), R_OK, 0))
		ret += git_config_from_file(fn, git_etc_gitconfig(),
					    data);

	if (xdg_config && !access_or_die(xdg_config, R_OK, ACCESS_EACCES_OK))
		ret += git_config_from_file(fn, xdg_config, data);

	if (user_config && !access_or_die(user_config, R_OK, ACCESS_EACCES_OK))
		ret += git_config_from_file(fn, user_config, data);

	if (repo_config && !access_or_die(repo_config, R_OK, 0))
		ret += git_config_from_file(fn, repo_config, data);

	if (git_config_from_parameters(fn, data) < 0)
		die(_("unable to parse command-line config"));

	free(xdg_config);
	free(user_config);
	free(repo_config);
