					unsetenv(*cmd->env);
			}
		}
		if (cmd->git_cmd)
			execv_git_cmd(cmd->argv);
		else if (cmd->use_shell)
			execv_shell_cmd(cmd->argv);
		else
			sane_execvp(cmd->argv[0], (char *const*) cmd->argv);
		if (errno == ENOENT) {
			if (!cmd->silent_exec_failure)
				error("cannot run %s: %s", cmd->argv[0],
