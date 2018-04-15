
	closedir (dh);

	if (filename[0] == '\0')
		fprintf (stderr, "Could not find plugin %s.\n", type);

	return (ret);
}
