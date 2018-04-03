	uniq(&other_cmds);
	exclude_cmds(&other_cmds, &main_cmds);

	if (main_cmds.cnt) {
		printf("available git commands in '%s'\n", exec_path);
		printf("----------------------------");
