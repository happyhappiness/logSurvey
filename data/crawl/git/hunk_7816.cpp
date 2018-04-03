 	return 0;
 }
 
+static int parseopt_dump(const struct option *o, const char *arg, int unset)
+{
+	struct strbuf *parsed = o->value;
+	if (unset)
+		strbuf_addf(parsed, " --no-%s", o->long_name);
+	else if (o->short_name)
+		strbuf_addf(parsed, " -%c", o->short_name);
+	else
+		strbuf_addf(parsed, " --%s", o->long_name);
+	if (arg) {
+		strbuf_addch(parsed, ' ');
+		sq_quote_buf(parsed, arg);
+	}
+	return 0;
+}
+
+static const char *skipspaces(const char *s)
+{
+	while (isspace(*s))
+		s++;
+	return s;
+}
+
+static int cmd_parseopt(int argc, const char **argv, const char *prefix)
+{
+	static int keep_dashdash = 0;
+	static char const * const parseopt_usage[] = {
+		"git-rev-parse --parseopt [options] -- [<args>...]",
+		NULL
+	};
+	static struct option parseopt_opts[] = {
+		OPT_BOOLEAN(0, "keep-dashdash", &keep_dashdash,
+					"keep the `--` passed as an arg"),
+		OPT_END(),
+	};
+
+	struct strbuf sb, parsed;
+	const char **usage = NULL;
+	struct option *opts = NULL;
+	int onb = 0, osz = 0, unb = 0, usz = 0;
+
+	strbuf_init(&parsed, 0);
+	strbuf_addstr(&parsed, "set --");
+	argc = parse_options(argc, argv, parseopt_opts, parseopt_usage,
+	                     PARSE_OPT_KEEP_DASHDASH);
+	if (argc < 1 || strcmp(argv[0], "--"))
+		usage_with_options(parseopt_usage, parseopt_opts);
+
+	strbuf_init(&sb, 0);
+	/* get the usage up to the first line with a -- on it */
+	for (;;) {
+		if (strbuf_getline(&sb, stdin, '\n') == EOF)
+			die("premature end of input");
+		ALLOC_GROW(usage, unb + 1, usz);
+		if (!strcmp("--", sb.buf)) {
+			if (unb < 1)
+				die("no usage string given before the `--' separator");
+			usage[unb] = NULL;
+			break;
+		}
+		usage[unb++] = strbuf_detach(&sb, NULL);
+	}
+
+	/* parse: (<short>|<short>,<long>|<long>)[=?]? SP+ <help> */
+	while (strbuf_getline(&sb, stdin, '\n') != EOF) {
+		const char *s;
+		struct option *o;
+
+		if (!sb.len)
+			continue;
+
+		ALLOC_GROW(opts, onb + 1, osz);
+		memset(opts + onb, 0, sizeof(opts[onb]));
+
+		o = &opts[onb++];
+		s = strchr(sb.buf, ' ');
+		if (!s || *sb.buf == ' ') {
+			o->type = OPTION_GROUP;
+			o->help = xstrdup(skipspaces(s));
+			continue;
+		}
+
+		o->type = OPTION_CALLBACK;
+		o->help = xstrdup(skipspaces(s));
+		o->value = &parsed;
+		o->callback = &parseopt_dump;
+		switch (s[-1]) {
+		case '=':
+			s--;
+			break;
+		case '?':
+			o->flags = PARSE_OPT_OPTARG;
+			s--;
+			break;
+		default:
+			o->flags = PARSE_OPT_NOARG;
+			break;
+		}
+
+		if (s - sb.buf == 1) /* short option only */
+			o->short_name = *sb.buf;
+		else if (sb.buf[1] != ',') /* long option only */
+			o->long_name = xmemdupz(sb.buf, s - sb.buf);
+		else {
+			o->short_name = *sb.buf;
+			o->long_name = xmemdupz(sb.buf + 2, s - sb.buf - 2);
+		}
+	}
+	strbuf_release(&sb);
+
+	/* put an OPT_END() */
+	ALLOC_GROW(opts, onb + 1, osz);
+	memset(opts + onb, 0, sizeof(opts[onb]));
+	argc = parse_options(argc, argv, opts, usage,
+	                     keep_dashdash ? PARSE_OPT_KEEP_DASHDASH : 0);
+
+	strbuf_addf(&parsed, " --");
+	sq_quote_argv(&parsed, argv, argc, 0);
+	puts(parsed.buf);
+	return 0;
+}
+
 int cmd_rev_parse(int argc, const char **argv, const char *prefix)
 {
 	int i, as_is = 0, verify = 0;
 	unsigned char sha1[20];
 
 	git_config(git_default_config);
 
+	if (argc > 1 && !strcmp("--parseopt", argv[1]))
+		return cmd_parseopt(argc - 1, argv + 1, prefix);
+
 	for (i = 1; i < argc; i++) {
 		const char *arg = argv[i];
 