	va_end (ap);
} /* void cmd_error */

cmd_status_t cmd_parse (char *buffer,
		cmd_t *ret_cmd, cmd_error_handler_t *err)
{
	char *command = NULL;
	int status;

	if ((buffer == NULL) || (ret_cmd == NULL))
	{
		errno = EINVAL;
		cmd_error (CMD_ERROR, err, "Invalid arguments to cmd_parse.");
		return CMD_ERROR;
	}

	if ((status = parse_string (&buffer, &command)) != 0)
	{
		cmd_error (CMD_PARSE_ERROR, err,
				"Failed to extract command from `%s'.", buffer);
		return (CMD_PARSE_ERROR);
	}
	assert (command != NULL);

	memset (ret_cmd, 0, sizeof (*ret_cmd));
	if (strcasecmp ("PUTVAL", command) == 0)
	{
		ret_cmd->type = CMD_PUTVAL;
		return cmd_parse_putval (buffer, &ret_cmd->cmd.putval, err);
	}
	else
	{
