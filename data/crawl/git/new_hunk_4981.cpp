	if (group_name && !user_name)
		die("--group supplied without --user");

	if (user_name)
		cred = prepare_credentials(user_name, group_name);

	if (strict_paths && (!ok_paths || !*ok_paths))
		die("option --strict-paths requires a whitelist");
