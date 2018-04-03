	if (!base)
		base = "";

	if (list) {
		for (i = 0; i < ARRAY_SIZE(archivers); i++)
			printf("%s\n", archivers[i].name);
