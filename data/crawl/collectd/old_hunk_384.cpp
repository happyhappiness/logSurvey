	vl.values = (value_t *) malloc (vl.values_len * sizeof (value_t));
	if (vl.values == NULL)
	{
		fprintf (fh, "-1 malloc failed.");
		return (-1);
	}

