 	}
 }
 
-void show_decorations(struct rev_info *opt, struct commit *commit)
+/*
+ * The caller makes sure there is no funny color before
+ * calling. format_decorations makes sure the same after return.
+ */
+void format_decorations(struct strbuf *sb,
+			const struct commit *commit,
+			int use_color)
 {
 	const char *prefix;
 	struct name_decoration *decoration;
 	const char *color_commit =
-		diff_get_color_opt(&opt->diffopt, DIFF_COMMIT);
+		diff_get_color(use_color, DIFF_COMMIT);
 	const char *color_reset =
-		decorate_get_color_opt(&opt->diffopt, DECORATION_NONE);
+		decorate_get_color(use_color, DECORATION_NONE);
 
-	if (opt->show_source && commit->util)
-		printf("\t%s", (char *) commit->util);
-	if (!opt->show_decorations)
-		return;
 	decoration = lookup_decoration(&name_decoration, &commit->object);
 	if (!decoration)
 		return;
 	prefix = " (";
 	while (decoration) {
-		printf("%s", prefix);
-		fputs(decorate_get_color_opt(&opt->diffopt, decoration->type),
-		      stdout);
+		strbuf_addstr(sb, color_commit);
+		strbuf_addstr(sb, prefix);
+		strbuf_addstr(sb, decorate_get_color(use_color, decoration->type));
 		if (decoration->type == DECORATION_REF_TAG)
-			fputs("tag: ", stdout);
-		printf("%s", decoration->name);
-		fputs(color_reset, stdout);
-		fputs(color_commit, stdout);
+			strbuf_addstr(sb, "tag: ");
+		strbuf_addstr(sb, decoration->name);
+		strbuf_addstr(sb, color_reset);
 		prefix = ", ";
 		decoration = decoration->next;
 	}
-	putchar(')');
+	strbuf_addstr(sb, color_commit);
+	strbuf_addch(sb, ')');
+	strbuf_addstr(sb, color_reset);
+}
+
+void show_decorations(struct rev_info *opt, struct commit *commit)
+{
+	struct strbuf sb = STRBUF_INIT;
+
+	if (opt->show_source && commit->util)
+		printf("\t%s", (char *) commit->util);
+	if (!opt->show_decorations)
+		return;
+	format_decorations(&sb, commit, opt->diffopt.use_color);
+	fputs(sb.buf, stdout);
+	strbuf_release(&sb);
 }
 
 static unsigned int digits_in_number(unsigned int number)
