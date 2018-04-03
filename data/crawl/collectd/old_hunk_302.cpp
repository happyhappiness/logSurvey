	else
	{
		if (print_timestamp)
			fprintf (fh, "[%s] %s%s\n", timestamp_str,
					print_level ? level_str : "",
					msg);
		else
			fprintf (fh, "%s%s\n", print_level ? level_str : "",
						msg);

		if (do_close != 0)
			fclose (fh);