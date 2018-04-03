	child_process.out = out;

	if (start_command(&child_process))
		return error("cannot fork to run external filter %s", params->cmd);

	sigchain_push(SIGPIPE, SIG_IGN);

