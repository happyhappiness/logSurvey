 	return isalnum(ch) || ch == '_';
 }
 
+static void output_color(struct grep_opt *opt, const void *data, size_t size,
+			 const char *color)
+{
+	if (opt->color && color && color[0]) {
+		opt->output(opt, color, strlen(color));
+		opt->output(opt, data, size);
+		opt->output(opt, GIT_COLOR_RESET, strlen(GIT_COLOR_RESET));
+	} else
+		opt->output(opt, data, size);
+}
+
+static void output_sep(struct grep_opt *opt, char sign)
+{
+	if (opt->null_following_name)
+		opt->output(opt, "\0", 1);
+	else
+		output_color(opt, &sign, 1, opt->color_sep);
+}
+
 static void show_name(struct grep_opt *opt, const char *name)
 {
-	opt->output(opt, name, strlen(name));
+	output_color(opt, name, strlen(name), opt->color_filename);
 	opt->output(opt, opt->null_following_name ? "\0" : "\n", 1);
 }
 
