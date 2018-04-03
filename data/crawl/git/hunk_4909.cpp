 #define OPT_SHORT 1
 #define OPT_UNSET 2
 
+static int optbug(const struct option *opt, const char *reason)
+{
+	if (opt->long_name)
+		return error("BUG: option '%s' %s", opt->long_name, reason);
+	return error("BUG: switch '%c' %s", opt->short_name, reason);
+}
+
 static int opterror(const struct option *opt, const char *reason, int flags)
 {
 	if (flags & OPT_SHORT)
