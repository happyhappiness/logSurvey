 static int grep_source_load(struct grep_source *gs);
 static int grep_source_is_binary(struct grep_source *gs);
 
+static struct grep_opt grep_defaults;
+
+/*
+ * Initialize the grep_defaults template with hardcoded defaults.
+ * We could let the compiler do this, but without C99 initializers
+ * the code gets unwieldy and unreadable, so...
+ */
+void init_grep_defaults(void)
+{
+	struct grep_opt *opt = &grep_defaults;
+
+	memset(opt, 0, sizeof(*opt));
+	opt->relative = 1;
+	opt->pathname = 1;
+	opt->regflags = REG_NEWLINE;
+	opt->max_depth = -1;
+	opt->pattern_type_option = GREP_PATTERN_TYPE_UNSPECIFIED;
+	opt->extended_regexp_option = 0;
+	strcpy(opt->color_context, "");
+	strcpy(opt->color_filename, "");
+	strcpy(opt->color_function, "");
+	strcpy(opt->color_lineno, "");
+	strcpy(opt->color_match, GIT_COLOR_BOLD_RED);
+	strcpy(opt->color_selected, "");
+	strcpy(opt->color_sep, GIT_COLOR_CYAN);
+	opt->color = -1;
+}
+
+static int parse_pattern_type_arg(const char *opt, const char *arg)
+{
+	if (!strcmp(arg, "default"))
+		return GREP_PATTERN_TYPE_UNSPECIFIED;
+	else if (!strcmp(arg, "basic"))
+		return GREP_PATTERN_TYPE_BRE;
+	else if (!strcmp(arg, "extended"))
+		return GREP_PATTERN_TYPE_ERE;
+	else if (!strcmp(arg, "fixed"))
+		return GREP_PATTERN_TYPE_FIXED;
+	else if (!strcmp(arg, "perl"))
+		return GREP_PATTERN_TYPE_PCRE;
+	die("bad %s argument: %s", opt, arg);
+}
+
+/*
+ * Read the configuration file once and store it in
+ * the grep_defaults template.
+ */
+int grep_config(const char *var, const char *value, void *cb)
+{
+	struct grep_opt *opt = &grep_defaults;
+	char *color = NULL;
+
+	if (userdiff_config(var, value) < 0)
+		return -1;
+
+	if (!strcmp(var, "grep.extendedregexp")) {
+		if (git_config_bool(var, value))
+			opt->extended_regexp_option = 1;
+		else
+			opt->extended_regexp_option = 0;
+		return 0;
+	}
+
+	if (!strcmp(var, "grep.patterntype")) {
+		opt->pattern_type_option = parse_pattern_type_arg(var, value);
+		return 0;
+	}
+
+	if (!strcmp(var, "grep.linenumber")) {
+		opt->linenum = git_config_bool(var, value);
+		return 0;
+	}
+
+	if (!strcmp(var, "color.grep"))
+		opt->color = git_config_colorbool(var, value);
+	else if (!strcmp(var, "color.grep.context"))
+		color = opt->color_context;
+	else if (!strcmp(var, "color.grep.filename"))
+		color = opt->color_filename;
+	else if (!strcmp(var, "color.grep.function"))
+		color = opt->color_function;
+	else if (!strcmp(var, "color.grep.linenumber"))
+		color = opt->color_lineno;
+	else if (!strcmp(var, "color.grep.match"))
+		color = opt->color_match;
+	else if (!strcmp(var, "color.grep.selected"))
+		color = opt->color_selected;
+	else if (!strcmp(var, "color.grep.separator"))
+		color = opt->color_sep;
+
+	if (color) {
+		if (!value)
+			return config_error_nonbool(var);
+		color_parse(value, var, color);
+	}
+	return 0;
+}
+
+/*
+ * Initialize one instance of grep_opt and copy the
+ * default values from the template we read the configuration
+ * information in an earlier call to git_config(grep_config).
+ */
+void grep_init(struct grep_opt *opt, const char *prefix)
+{
+	struct grep_opt *def = &grep_defaults;
+
+	memset(opt, 0, sizeof(*opt));
+	opt->prefix = prefix;
+	opt->prefix_length = (prefix && *prefix) ? strlen(prefix) : 0;
+	opt->pattern_tail = &opt->pattern_list;
+	opt->header_tail = &opt->header_list;
+
+	opt->color = def->color;
+	opt->extended_regexp_option = def->extended_regexp_option;
+	opt->pattern_type_option = def->pattern_type_option;
+	opt->linenum = def->linenum;
+	opt->max_depth = def->max_depth;
+	opt->pathname = def->pathname;
+	opt->regflags = def->regflags;
+	opt->relative = def->relative;
+
+	strcpy(opt->color_context, def->color_context);
+	strcpy(opt->color_filename, def->color_filename);
+	strcpy(opt->color_function, def->color_function);
+	strcpy(opt->color_lineno, def->color_lineno);
+	strcpy(opt->color_match, def->color_match);
+	strcpy(opt->color_selected, def->color_selected);
+	strcpy(opt->color_sep, def->color_sep);
+}
 
 static struct grep_pat *create_grep_pat(const char *pat, size_t patlen,
 					const char *origin, int no,
