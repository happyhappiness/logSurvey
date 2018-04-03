 	}
 }
 
-void show_decorations(struct commit *commit)
+void show_decorations(struct rev_info *opt, struct commit *commit)
 {
 	const char *prefix;
 	struct name_decoration *decoration;
 
+	if (opt->show_source && commit->util)
+		printf(" %s", (char *) commit->util);
 	decoration = lookup_decoration(&name_decoration, &commit->object);
 	if (!decoration)
 		return;
