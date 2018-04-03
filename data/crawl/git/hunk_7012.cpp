 #define DEFAULT_INDENT1 6
 #define DEFAULT_INDENT2 9
 
-static void parse_wrap_args(const char *arg, int *in1, int *in2, int *wrap)
+static int parse_wrap_args(const struct option *opt, const char *arg, int unset)
 {
-	arg += 2; /* skip -w */
-
-	*wrap = parse_uint(&arg, ',');
-	if (*wrap < 0)
-		die(wrap_arg_usage);
-	*in1 = parse_uint(&arg, ',');
-	if (*in1 < 0)
-		die(wrap_arg_usage);
-	*in2 = parse_uint(&arg, '\0');
-	if (*in2 < 0)
-		die(wrap_arg_usage);
-
-	if (!*wrap)
-		*wrap = DEFAULT_WRAPLEN;
-	if (!*in1)
-		*in1 = DEFAULT_INDENT1;
-	if (!*in2)
-		*in2 = DEFAULT_INDENT2;
-	if (*wrap &&
-	    ((*in1 && *wrap <= *in1) ||
-	     (*in2 && *wrap <= *in2)))
-		die(wrap_arg_usage);
+	struct shortlog *log = opt->value;
+
+	log->wrap_lines = !unset;
+	if (unset)
+		return 0;
+	if (!arg) {
+		log->wrap = DEFAULT_WRAPLEN;
+		log->in1 = DEFAULT_INDENT1;
+		log->in2 = DEFAULT_INDENT2;
+		return 0;
+	}
+
+	log->wrap = parse_uint(&arg, ',', DEFAULT_WRAPLEN);
+	log->in1 = parse_uint(&arg, ',', DEFAULT_INDENT1);
+	log->in2 = parse_uint(&arg, '\0', DEFAULT_INDENT2);
+	if (log->wrap < 0 || log->in1 < 0 || log->in2 < 0)
+		return error(wrap_arg_usage);
+	if (log->wrap &&
+	    ((log->in1 && log->wrap <= log->in1) ||
+	     (log->in2 && log->wrap <= log->in2)))
+		return error(wrap_arg_usage);
+	return 0;
 }
 
 void shortlog_init(struct shortlog *log)
