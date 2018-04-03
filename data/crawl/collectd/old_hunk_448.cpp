		return (NULL);
	}

	fprintf (stderr, "cf_read_generic (path = %s, depth = %i);", path, depth);

	status = stat (path, &statbuf);
	if (status != 0)
