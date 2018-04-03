 {
 	const char *prefix;
 	struct name_decoration *decoration;
+	const char *color_commit =
+		diff_get_color_opt(&opt->diffopt, DIFF_COMMIT);
+	const char *color_reset =
+		decorate_get_color_opt(&opt->diffopt, DECORATION_NONE);
 
 	if (opt->show_source && commit->util)
 		printf("\t%s", (char *) commit->util);
