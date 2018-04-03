		return (1);

	return (0);
} /* int set_option */

/*
 * public API
 */

cmd_status_t cmd_parse_putval (char *buffer,
		cmd_putval_t *ret_putval, cmd_error_handler_t *err)
{
	char *identifier;
	char *hostname;
	char *plugin;
	char *plugin_instance;
	char *type;
	char *type_instance;
	int   status;

	char *identifier_copy;

	const data_set_t *ds;
	value_list_t vl = VALUE_LIST_INIT;
	vl.values = NULL;

	identifier = NULL;
	status = parse_string (&buffer, &identifier);
	if (status != 0)
	{
		cmd_error (CMD_PARSE_ERROR, err, "Cannot parse identifier.");
		return (CMD_PARSE_ERROR);
	}
	assert (identifier != NULL);

