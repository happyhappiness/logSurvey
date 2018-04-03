		return (CMD_ERROR);
	}

	ret_putval->identifier = identifier_copy;
	if (ret_putval->identifier == NULL)
	{
		cmd_error (CMD_ERROR, err, "malloc failed.");
		cmd_destroy_putval (ret_putval);
