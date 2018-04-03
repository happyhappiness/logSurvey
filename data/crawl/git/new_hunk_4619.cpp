
	patterns = fopen(arg, "r");
	if (!patterns)
		die_errno(_("cannot open '%s'"), arg);
	while (strbuf_getline(&sb, patterns, '\n') == 0) {
		char *s;
		size_t len;
