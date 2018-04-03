	if (path)
		repo = xstrdup(make_nonrelative_path(repo_name));
	else if (!strchr(repo_name, ':'))
		repo = xstrdup(make_absolute_path(repo_name));
	else
		repo = repo_name;
	is_local = path && !is_bundle;
