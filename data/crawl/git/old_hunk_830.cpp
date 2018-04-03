	if (opts->allow_empty_message)
		argv_array_push(&cmd.args, "--allow-empty-message");


	return run_command(&cmd);
}