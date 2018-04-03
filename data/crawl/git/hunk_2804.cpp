 		usage_with_options(git_tag_usage, options);
 
 	finalize_colopts(&colopts, -1);
-	if (cmdmode == 'l' && lines != -1) {
+	if (cmdmode == 'l' && filter.lines != -1) {
 		if (explicitly_enable_column(colopts))
 			die(_("--column and -n are incompatible"));
 		colopts = 0;
