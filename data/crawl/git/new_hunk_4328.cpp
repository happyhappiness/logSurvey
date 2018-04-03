	if (path)
		repo = xstrdup(absolute_path(repo_name));
	else if (!strchr(repo_name, ':'))
		die(_("repository '%s' does not exist"), repo_name);
	else
		repo = repo_name;
	is_local = path && !is_bundle;