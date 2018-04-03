
	patterns = fopen(arg, "r");
	if (!patterns)
		die("'%s': %s", arg, strerror(errno));
	while (strbuf_getline(&sb, patterns, '\n') == 0) {
		/* ignore empty line like grep does */
		if (sb.len == 0)
