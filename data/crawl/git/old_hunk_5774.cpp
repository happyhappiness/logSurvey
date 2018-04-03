	}

	cmd->pid = mingw_spawnvpe(cmd->argv[0], cmd->argv, env);

	if (cmd->env)
		free_environ(env);
