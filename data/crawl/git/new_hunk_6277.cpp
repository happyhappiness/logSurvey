			return (struct ref *)list;
	return NULL;
}

/*
 * generate a format suitable for scanf from a ref_rev_parse_rules
 * rule, that is replace the "%.*s" spec with a "%s" spec
 */
static void gen_scanf_fmt(char *scanf_fmt, const char *rule)
{
	char *spec;

	spec = strstr(rule, "%.*s");
	if (!spec || strstr(spec + 4, "%.*s"))
		die("invalid rule in ref_rev_parse_rules: %s", rule);

	/* copy all until spec */
	strncpy(scanf_fmt, rule, spec - rule);
	scanf_fmt[spec - rule] = '\0';
	/* copy new spec */
	strcat(scanf_fmt, "%s");
	/* copy remaining rule */
	strcat(scanf_fmt, spec + 4);

	return;
}

char *shorten_unambiguous_ref(const char *ref)
{
	int i;
	static char **scanf_fmts;
	static int nr_rules;
	char *short_name;

	/* pre generate scanf formats from ref_rev_parse_rules[] */
	if (!nr_rules) {
		size_t total_len = 0;

		/* the rule list is NULL terminated, count them first */
		for (; ref_rev_parse_rules[nr_rules]; nr_rules++)
			/* no +1 because strlen("%s") < strlen("%.*s") */
			total_len += strlen(ref_rev_parse_rules[nr_rules]);

		scanf_fmts = xmalloc(nr_rules * sizeof(char *) + total_len);

		total_len = 0;
		for (i = 0; i < nr_rules; i++) {
			scanf_fmts[i] = (char *)&scanf_fmts[nr_rules]
					+ total_len;
			gen_scanf_fmt(scanf_fmts[i], ref_rev_parse_rules[i]);
			total_len += strlen(ref_rev_parse_rules[i]);
		}
	}

	/* bail out if there are no rules */
	if (!nr_rules)
		return xstrdup(ref);

	/* buffer for scanf result, at most ref must fit */
	short_name = xstrdup(ref);

	/* skip first rule, it will always match */
	for (i = nr_rules - 1; i > 0 ; --i) {
		int j;
		int short_name_len;

		if (1 != sscanf(ref, scanf_fmts[i], short_name))
			continue;

		short_name_len = strlen(short_name);

		/*
		 * check if the short name resolves to a valid ref,
		 * but use only rules prior to the matched one
		 */
		for (j = 0; j < i; j++) {
			const char *rule = ref_rev_parse_rules[j];
			unsigned char short_objectname[20];
			char refname[PATH_MAX];

			/*
			 * the short name is ambiguous, if it resolves
			 * (with this previous rule) to a valid ref
			 * read_ref() returns 0 on success
			 */
			mksnpath(refname, sizeof(refname),
				 rule, short_name_len, short_name);
			if (!read_ref(refname, short_objectname))
				break;
		}

		/*
		 * short name is non-ambiguous if all previous rules
		 * haven't resolved to a valid ref
		 */
		if (j == i)
			return short_name;
	}

	free(short_name);
	return xstrdup(ref);
}
