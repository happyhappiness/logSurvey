	launch_editor(file, NULL, NULL);

	if (stat(file, &st))
		die("Could not stat '%s'", file);
	if (!st.st_size)
		die("Empty patch. Aborted.");

