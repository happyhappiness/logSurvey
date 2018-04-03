	if (close(child_process.in))
		write_err = 1;
	if (write_err)
		error("cannot feed the input to external filter '%s'", params->cmd);

	sigchain_pop(SIGPIPE);

	status = finish_command(&child_process);
	if (status)
		error("external filter '%s' failed %d", params->cmd, status);

	strbuf_release(&cmd);
	return (write_err || status);
