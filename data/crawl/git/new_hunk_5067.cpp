	return execv_git_cmd(cvsserver_argv);
}

static int is_valid_cmd_name(const char *cmd)
{
	/* Test command contains no . or / characters */
	return cmd[strcspn(cmd, "./")] == '\0';
}

static char *make_cmd(const char *prog)
{
	char *prefix = xmalloc((strlen(prog) + strlen(COMMAND_DIR) + 2));
	strcpy(prefix, COMMAND_DIR);
	strcat(prefix, "/");
	strcat(prefix, prog);
	return prefix;
}

static void cd_to_homedir(void)
{
	const char *home = getenv("HOME");
	if (!home)
		die("could not determine user's home directory; HOME is unset");
	if (chdir(home) == -1)
		die("could not chdir to user's home directory");
}

static struct commands {
	const char *name;
