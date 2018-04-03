	if (group_name && !user_name)
		die("--group supplied without --user");

	if (user_name) {
		pass = getpwnam(user_name);
		if (!pass)
			die("user not found - %s", user_name);

		if (!group_name)
			gid = pass->pw_gid;
		else {
			group = getgrnam(group_name);
			if (!group)
				die("group not found - %s", group_name);

			gid = group->gr_gid;
		}
	}

	if (strict_paths && (!ok_paths || !*ok_paths))
		die("option --strict-paths requires a whitelist");
