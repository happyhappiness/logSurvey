
static int unmerged_files(void)
{
	char b;
	ssize_t len;
	struct child_process cmd;
	const char *argv_ls_files[] = {"ls-files", "--unmerged", NULL};

	memset(&cmd, 0, sizeof(cmd));
	cmd.argv = argv_ls_files;
	cmd.git_cmd = 1;
	cmd.out = -1;

	if (start_command(&cmd))
		die("Could not run sub-command: git ls-files");

	len = xread(cmd.out, &b, 1);
	if (len < 0)
		die("Could not read output from git ls-files: %s",
						strerror(errno));
	finish_command(&cmd);

	return len;
}

static int reset_index_file(const unsigned char *sha1, int is_hard_reset)
