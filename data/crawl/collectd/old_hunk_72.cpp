	value_list_t vl = VALUE_LIST_INIT;
	size_t i;

	if (argc < 2)
	{
		cmd_error (CMD_PARSE_ERROR, err,
