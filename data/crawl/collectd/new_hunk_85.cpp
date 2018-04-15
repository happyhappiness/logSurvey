	va_end (ap);
} /* void cmd_error */

cmd_status_t cmd_parsev (size_t argc, char **argv,
		cmd_t *ret_cmd, cmd_error_handler_t *err)
{
	char *command = NULL;

	if ((argc < 1) || (argv == NULL) || (ret_cmd == NULL))
	{
		errno = EINVAL;
		cmd_error (CMD_ERROR, err, "Missing command.");
		return CMD_ERROR;
	}

	memset (ret_cmd, 0, sizeof (*ret_cmd));
	command = argv[0];
	if (strcasecmp ("PUTVAL", command) == 0)
	{
		ret_cmd->type = CMD_PUTVAL;
		return cmd_parse_putval (argc - 1, argv + 1,
				&ret_cmd->cmd.putval, err);
	}
	else
	{
