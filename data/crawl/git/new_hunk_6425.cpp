	if (!base)
		base = "";

	if (output)
		create_output_file(output);

	if (list) {
		for (i = 0; i < ARRAY_SIZE(archivers); i++)
			printf("%s\n", archivers[i].name);
