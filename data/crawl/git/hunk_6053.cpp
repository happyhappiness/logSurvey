 	die("unable to grep from object of type %s", typename(obj->type));
 }
 
-static const char builtin_grep_usage[] =
-"git grep <option>* [-e] <pattern> <rev>* [[--] <path>...]";
+int context_callback(const struct option *opt, const char *arg, int unset)
+{
+	struct grep_opt *grep_opt = opt->value;
+	int value;
+	const char *endp;
+
+	if (unset) {
+		grep_opt->pre_context = grep_opt->post_context = 0;
+		return 0;
+	}
+	value = strtol(arg, (char **)&endp, 10);
+	if (*endp) {
+		return error("switch `%c' expects a numerical value",
+			     opt->short_name);
+	}
+	grep_opt->pre_context = grep_opt->post_context = value;
+	return 0;
+}
+
+int file_callback(const struct option *opt, const char *arg, int unset)
+{
+	struct grep_opt *grep_opt = opt->value;
+	FILE *patterns;
+	int lno = 0;
+	struct strbuf sb;
+
+	patterns = fopen(arg, "r");
+	if (!patterns)
+		die("'%s': %s", arg, strerror(errno));
+	while (strbuf_getline(&sb, patterns, '\n') == 0) {
+		/* ignore empty line like grep does */
+		if (sb.len == 0)
+			continue;
+		append_grep_pattern(grep_opt, strbuf_detach(&sb, NULL), arg,
+				    ++lno, GREP_PATTERN);
+	}
+	fclose(patterns);
+	strbuf_release(&sb);
+	return 0;
+}
+
+int not_callback(const struct option *opt, const char *arg, int unset)
+{
+	struct grep_opt *grep_opt = opt->value;
+	append_grep_pattern(grep_opt, "--not", "command line", 0, GREP_NOT);
+	return 0;
+}
+
+int and_callback(const struct option *opt, const char *arg, int unset)
+{
+	struct grep_opt *grep_opt = opt->value;
+	append_grep_pattern(grep_opt, "--and", "command line", 0, GREP_AND);
+	return 0;
+}
+
+int open_callback(const struct option *opt, const char *arg, int unset)
+{
+	struct grep_opt *grep_opt = opt->value;
+	append_grep_pattern(grep_opt, "(", "command line", 0, GREP_OPEN_PAREN);
+	return 0;
+}
+
+int close_callback(const struct option *opt, const char *arg, int unset)
+{
+	struct grep_opt *grep_opt = opt->value;
+	append_grep_pattern(grep_opt, ")", "command line", 0, GREP_CLOSE_PAREN);
+	return 0;
+}
+
+int pattern_callback(const struct option *opt, const char *arg, int unset)
+{
+	struct grep_opt *grep_opt = opt->value;
+	append_grep_pattern(grep_opt, arg, "-e option", 0, GREP_PATTERN);
+	return 0;
+}
 
-static const char emsg_invalid_context_len[] =
-"%s: invalid context length argument";
-static const char emsg_missing_context_len[] =
-"missing context length argument";
-static const char emsg_missing_argument[] =
-"option requires an argument -%s";
+int help_callback(const struct option *opt, const char *arg, int unset)
+{
+	return -1;
+}
 
 int cmd_grep(int argc, const char **argv, const char *prefix)
 {
