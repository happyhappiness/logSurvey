	}
}

void show_decorations(struct rev_info *opt, struct commit *commit)
{
	const char *prefix;
	struct name_decoration *decoration;
	const char *color_commit =
		diff_get_color_opt(&opt->diffopt, DIFF_COMMIT);
	const char *color_reset =
		decorate_get_color_opt(&opt->diffopt, DECORATION_NONE);

	if (opt->show_source && commit->util)
		printf("\t%s", (char *) commit->util);
	if (!opt->show_decorations)
		return;
	decoration = lookup_decoration(&name_decoration, &commit->object);
	if (!decoration)
		return;
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
	putchar(')');
}

static unsigned int digits_in_number(unsigned int number)
