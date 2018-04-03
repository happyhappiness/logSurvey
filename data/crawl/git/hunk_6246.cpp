 	ctx->out  = argv;
 	ctx->cpidx = ((flags & PARSE_OPT_KEEP_ARGV0) != 0);
 	ctx->flags = flags;
+	if ((flags & PARSE_OPT_KEEP_UNKNOWN) &&
+	    (flags & PARSE_OPT_STOP_AT_NON_OPTION))
+		die("STOP_AT_NON_OPTION and KEEP_UNKNOWN don't go together");
 }
 
 static int usage_with_options_internal(const char * const *,
