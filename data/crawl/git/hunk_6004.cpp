 	exit(129);
 }
 
+void usage_msg_opt(const char *msg,
+		   const char * const *usagestr,
+		   const struct option *options)
+{
+	fprintf(stderr, "%s\n\n", msg);
+	usage_with_options(usagestr, options);
+}
+
 int parse_options_usage(const char * const *usagestr,
 			const struct option *opts)
 {