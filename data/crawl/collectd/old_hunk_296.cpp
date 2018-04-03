
	printf ("%s: %g average |", status_str, average);
	for (i = 0; i < values_num; i++)
		printf (" %s=%g;;;;", values_names[i], values[i]);
	printf ("\n");

	return (status_code);
