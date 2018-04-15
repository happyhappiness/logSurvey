
	printf ("%s: %g sum |", status_str, total);
	for (i = 0; i < values_num; i++)
		printf (" %s=%f;;;;", values_names[i], values[i]);
	printf ("\n");

	return (status_code);