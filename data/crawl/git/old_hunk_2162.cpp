
	expanded = expand_user_path(path);
	if (!expanded)
		return error("Could not expand include path '%s'", path);
	path = expanded;

	/*
