	return 0;
}

int cmd_update_index(int argc, const char **argv, const char *prefix)
{
	int i, newfd, entries, has_errors = 0, line_termination = '\n';
	int allow_options = 1;
	int read_from_stdin = 0;
	int prefix_length = prefix ? strlen(prefix) : 0;
	char set_executable_bit = 0;
	unsigned int refresh_flags = 0;
	int lock_error = 0;
	struct lock_file *lock_file;

	git_config(git_default_config, NULL);

