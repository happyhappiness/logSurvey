		{
			us_handle_putval (fh, fields, fields_num);
		}
		else if (strcasecmp (fields[0], "listval") == 0)
		{
			us_handle_listval (fh, fields, fields_num);
		}
		else
		{
			fprintf (fh, "-1 Unknown command: %s\n", fields[0]);