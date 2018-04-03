	return builtin_exec_path;
}


int execv_git_cmd(const char **argv)
{
	char git_command[PATH_MAX + 1];
	int i;
	const char *paths[] = { argv_exec_path,
				getenv(EXEC_PATH_ENVIRONMENT),
				builtin_exec_path };

	for (i = 0; i < ARRAY_SIZE(paths); ++i) {
		size_t len;
		int rc;
		const char *exec_dir = paths[i];
		const char *tmp;

		if (!exec_dir || !*exec_dir) continue;

		if (*exec_dir != '/') {
			if (!getcwd(git_command, sizeof(git_command))) {
				fprintf(stderr, "git: cannot determine "
					"current directory: %s\n",
					strerror(errno));
				break;
			}
			len = strlen(git_command);

			/* Trivial cleanup */
			while (!prefixcmp(exec_dir, "./")) {
				exec_dir += 2;
				while (*exec_dir == '/')
					exec_dir++;
			}

			rc = snprintf(git_command + len,
				      sizeof(git_command) - len, "/%s",
				      exec_dir);
			if (rc < 0 || rc >= sizeof(git_command) - len) {
				fprintf(stderr, "git: command name given "
					"is too long.\n");
				break;
			}
		} else {
			if (strlen(exec_dir) + 1 > sizeof(git_command)) {
				fprintf(stderr, "git: command name given "
					"is too long.\n");
				break;
			}
			strcpy(git_command, exec_dir);
		}

		len = strlen(git_command);
		rc = snprintf(git_command + len, sizeof(git_command) - len,
			      "/git-%s", argv[0]);
		if (rc < 0 || rc >= sizeof(git_command) - len) {
			fprintf(stderr,
				"git: command name given is too long.\n");
			break;
		}

		/* argv[0] must be the git command, but the argv array
		 * belongs to the caller, and my be reused in
		 * subsequent loop iterations. Save argv[0] and
		 * restore it on error.
		 */

		tmp = argv[0];
		argv[0] = git_command;

		trace_argv_printf(argv, -1, "trace: exec:");

		/* execve() can only ever return if it fails */
		execve(git_command, (char **)argv, environ);

		trace_printf("trace: exec failed: %s\n", strerror(errno));

		argv[0] = tmp;
	}
	return -1;

}


