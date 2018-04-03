	return sort;
}

int cmd_for_each_ref(int ac, const char **av, const char *prefix)
{
	int i, num_refs;
	const char *format = NULL;
	struct ref_sort *sort = NULL, **sort_tail = &sort;
	int maxcount = 0;
	int quote_style = -1; /* unspecified yet */
	struct refinfo **refs;
	struct grab_ref_cbdata cbdata;

	for (i = 1; i < ac; i++) {
		const char *arg = av[i];
		if (arg[0] != '-')
			break;
		if (!strcmp(arg, "--")) {
			i++;
			break;
		}
		if (!prefixcmp(arg, "--format=")) {
			if (format)
				die("more than one --format?");
			format = arg + 9;
			continue;
		}
		if (!strcmp(arg, "-s") || !strcmp(arg, "--shell") ) {
			if (0 <= quote_style)
				die("more than one quoting style?");
			quote_style = QUOTE_SHELL;
			continue;
		}
		if (!strcmp(arg, "-p") || !strcmp(arg, "--perl") ) {
			if (0 <= quote_style)
				die("more than one quoting style?");
			quote_style = QUOTE_PERL;
			continue;
		}
		if (!strcmp(arg, "--python") ) {
			if (0 <= quote_style)
				die("more than one quoting style?");
			quote_style = QUOTE_PYTHON;
			continue;
		}
		if (!strcmp(arg, "--tcl") ) {
			if (0 <= quote_style)
				die("more than one quoting style?");
			quote_style = QUOTE_TCL;
			continue;
		}
		if (!prefixcmp(arg, "--count=")) {
			if (maxcount)
				die("more than one --count?");
			maxcount = atoi(arg + 8);
			if (maxcount <= 0)
				die("The number %s did not parse", arg);
			continue;
		}
		if (!prefixcmp(arg, "--sort=")) {
			struct ref_sort *s = xcalloc(1, sizeof(*s));
			int len;

			s->next = NULL;
			*sort_tail = s;
			sort_tail = &s->next;

			arg += 7;
			if (*arg == '-') {
				s->reverse = 1;
				arg++;
			}
			len = strlen(arg);
			sort->atom = parse_atom(arg, arg+len);
			continue;
		}
		break;
	}
	if (quote_style < 0)
		quote_style = QUOTE_NONE;

	if (!sort)
		sort = default_sort();
	sort_atom_limit = used_atom_cnt;
	if (!format)
		format = "%(objectname) %(objecttype)\t%(refname)";

	verify_format(format);

	memset(&cbdata, 0, sizeof(cbdata));
	cbdata.grab_pattern = av + i;
	for_each_ref(grab_single_ref, &cbdata);
	refs = cbdata.grab_array;
	num_refs = cbdata.grab_cnt;