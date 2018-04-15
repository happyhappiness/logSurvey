		return (-1);
	}

	fprintf (fh, "GETVAL %s/%s\n", hostname_g, value_string_g);
	fflush (fh);

	if (fgets (buffer, sizeof (buffer), fh) == NULL)
