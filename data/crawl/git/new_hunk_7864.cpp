	return sort;
}

int opt_parse_sort(const struct option *opt, const char *arg, int unset)
{
	struct ref_sort **sort_tail = opt->value;
	struct ref_sort *s;
	int len;

	if (!arg) /* should --no-sort void the list ? */
		return -1;

	*sort_tail = s = xcalloc(1, sizeof(*s));
	sort_tail = &s->next;

	if (*arg == '-') {
		s->reverse = 1;
		arg++;
	}
	len = strlen(arg);
	s->atom = parse_atom(arg, arg+len);
	return 0;
}

static char const * const for_each_ref_usage[] = {
	"git-for-each-ref [options] [<pattern>]",
	NULL
};

int cmd_for_each_ref(int argc, const char **argv, const char *prefix)
{
	int i, num_refs;
	const char *format = "%(objectname) %(objecttype)\t%(refname)";
	struct ref_sort *sort = NULL, **sort_tail = &sort;
	int maxcount = 0, quote_style;
	int quote_shell = 0, quote_perl = 0, quote_python = 0, quote_tcl = 0;
	struct refinfo **refs;
	struct grab_ref_cbdata cbdata;

	struct option opts[] = {
		OPT_BOOLEAN('s', "shell", &quote_shell, "quote placeholders suitably for shells"),
		OPT_BOOLEAN('p', "perl",  &quote_perl, "quote placeholders suitably for perl"),
		OPT_BOOLEAN( 0 , "python", &quote_python, "quote placeholders suitably for python"),
		OPT_BOOLEAN( 0 , "tcl",  &quote_tcl, "quote placeholders suitably for tcl"),

		OPT_GROUP(""),
		OPT_INTEGER( 0 , "count", &maxcount, "show only <n> matched refs"),
		OPT_STRING(  0 , "format", &format, "format", "format to use for the output"),
		OPT_CALLBACK(0 , "sort", &sort_tail, "key",
		            "field name to sort on", &opt_parse_sort),
		OPT_END(),
	};

	parse_options(argc, argv, opts, for_each_ref_usage, 0);
	if (maxcount < 0) {
		error("invalid --count argument: `%d'", maxcount);
		usage_with_options(for_each_ref_usage, opts);
	}
	if (quote_shell + quote_perl + quote_python + quote_tcl > 1) {
		error("more than one quoting style ?");
		usage_with_options(for_each_ref_usage, opts);
	}
	if (verify_format(format))
		usage_with_options(for_each_ref_usage, opts);

	quote_style = QUOTE_SHELL * quote_shell + QUOTE_PERL * quote_perl +
		QUOTE_PYTHON * quote_python + QUOTE_TCL * quote_tcl;
	if (!sort)
		sort = default_sort();
	sort_atom_limit = used_atom_cnt;

	memset(&cbdata, 0, sizeof(cbdata));
	cbdata.grab_pattern = argv;
	for_each_ref(grab_single_ref, &cbdata);
	refs = cbdata.grab_array;
	num_refs = cbdata.grab_cnt;