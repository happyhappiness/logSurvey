
		switch (opts->type) {
		case OPTION_INTEGER:
			pos += fprintf(stderr, " <n>");
			break;
		case OPTION_STRING:
			if (opts->argh)
				pos += fprintf(stderr, " <%s>", opts->argh);
			else
				pos += fprintf(stderr, " ...");
			break;
		default:
			break;
