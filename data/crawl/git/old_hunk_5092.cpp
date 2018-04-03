	char *end;
	int width = options->stat_width;
	int name_width = options->stat_name_width;

	arg += strlen("--stat");
	end = (char *)arg;

	switch (*arg) {
	case '-':
		if (!prefixcmp(arg, "-width="))
			width = strtoul(arg + 7, &end, 10);
		else if (!prefixcmp(arg, "-name-width="))
			name_width = strtoul(arg + 12, &end, 10);
		break;
	case '=':
		width = strtoul(arg+1, &end, 10);
