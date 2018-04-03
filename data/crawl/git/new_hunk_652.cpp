					unsetenv(*cmd->env);
			}
		}

		sane_execvp(argv.argv[0], (char *const *) argv.argv);

		if (errno == ENOENT) {
			if (!cmd->silent_exec_failure)
				error("cannot run %s: %s", cmd->argv[0],
