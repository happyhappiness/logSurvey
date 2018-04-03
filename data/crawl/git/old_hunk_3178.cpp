		not_found("Repository not exported: '%s'", dir);

	http_config();
	cmd->imp(cmd_arg);
	return 0;
}
