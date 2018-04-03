		return (-1);
	}

	fprintf (fh, "GETVAL %s\n", value_string_g);
	fflush (fh);

	if (fgets (buffer, sizeof (buffer), fh) == NULL)
