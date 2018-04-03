	else if (cmd->out > 1)
		fhout = dup(cmd->out);

	if (cmd->env)
		env = make_augmented_environ(cmd->env);

