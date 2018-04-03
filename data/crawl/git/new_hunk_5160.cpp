	prefix = " (";
	while (decoration) {
		printf("%s", prefix);
		fputs(decorate_get_color_opt(&opt->diffopt, decoration->type),
		      stdout);
		if (decoration->type == DECORATION_REF_TAG)
			fputs("tag: ", stdout);
		printf("%s", decoration->name);
		fputs(color_reset, stdout);
		fputs(color_commit, stdout);
		prefix = ", ";
		decoration = decoration->next;
	}