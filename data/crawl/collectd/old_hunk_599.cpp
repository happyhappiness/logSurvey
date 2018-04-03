	DBG ("shortvar = %s, var = %s, arguments = %s, value = %s, ...",
			shortvar, var, arguments, value);

	if (flags == LC_FLAGS_SECTIONSTART)
	{
		if (nesting_depth != 0)
		{
			fprintf (stderr, ERR_NOT_NESTED);
			return (LC_CBRET_ERROR);
		}

		if (arguments == NULL)
		{
			fprintf (stderr, ERR_NEEDS_ARG, shortvar);
			return (LC_CBRET_ERROR);
		}

		nesting_depth++;

		if (((operating_mode == MODE_CLIENT)
					&& (strcasecmp (arguments, "Client") == 0))
				|| ((operating_mode == MODE_SERVER)
					&& (strcasecmp (arguments, "Server") == 0))
				|| ((operating_mode == MODE_LOCAL)
					&& (strcasecmp (arguments, "Local") == 0)))
		{
			return (LC_CBRET_OKAY);
		}
		else
		{
			return (LC_CBRET_IGNORESECTION);
		}
	}
	else if (flags == LC_FLAGS_SECTIONEND)
	{
		nesting_depth--;

		return (LC_CBRET_OKAY);
	}
	else
	{
		fprintf (stderr, ERR_SECTION_ONLY, shortvar);
		return (LC_CBRET_ERROR);
	}

}

/*
