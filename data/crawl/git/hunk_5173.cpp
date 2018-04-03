 	}
 	fputc('\n', outfile);
 
+	if (!err && ctx && ctx->flags & PARSE_OPT_SHELL_EVAL)
+		fputs("EOF\n", outfile);
+
 	return PARSE_OPT_HELP;
 }
 
 void usage_with_options(const char * const *usagestr,
 			const struct option *opts)
 {
-	usage_with_options_internal(usagestr, opts, 0, 1);
+	usage_with_options_internal(NULL, usagestr, opts, 0, 1);
 	exit(129);
 }
 
