	uniq(&other_cmds);
	exclude_cmds(&other_cmds, &main_cmds);

	return longest;
}

static void list_commands(void)
{
	unsigned int longest = load_command_list();
	const char *exec_path = git_exec_path();

	if (main_cmds.cnt) {
		printf("available git commands in '%s'\n", exec_path);
		printf("----------------------------");
