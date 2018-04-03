 
 static enum wt_status_format status_format = STATUS_FORMAT_UNSPECIFIED;
 
+static int opt_parse_porcelain(const struct option *opt, const char *arg, int unset)
+{
+	enum wt_status_format *value = (enum wt_status_format *)opt->value;
+	if (unset)
+		*value = STATUS_FORMAT_NONE;
+	else if (!arg)
+		*value = STATUS_FORMAT_PORCELAIN;
+	else if (!strcmp(arg, "v1") || !strcmp(arg, "1"))
+		*value = STATUS_FORMAT_PORCELAIN;
+	else
+		die("unsupported porcelain version '%s'", arg);
+
+	return 0;
+}
+
 static int opt_parse_m(const struct option *opt, const char *arg, int unset)
 {
 	struct strbuf *buf = opt->value;
