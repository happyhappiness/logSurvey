			close(cmd->out);
		}

		if (cmd->git_cmd) {
			execv_git_cmd(cmd->argv);
		} else {
