 	DIFF_OPT_CLR(&revs.diffopt, FOLLOW_RENAMES);
 	argc = parse_options_end(&ctx);
 
+	if (incremental || (output_option & OUTPUT_PORCELAIN)) {
+		if (show_progress > 0)
+			die("--progress can't be used with --incremental or porcelain formats");
+		show_progress = 0;
+	} else if (show_progress < 0)
+		show_progress = isatty(2);
+
 	if (0 < abbrev)
 		/* one more abbrev length is needed for the boundary commit */
 		abbrev++;
