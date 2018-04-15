	else
	{
		if (print_timestamp)
			fprintf (fh, "[%s] %s\n", timestamp_str, msg);
		else
			fprintf (fh, "%s\n", msg);

		if (do_close != 0)
			fclose (fh);
