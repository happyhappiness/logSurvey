 	GIT_COLOR_NORMAL,	/* FUNCINFO */
 };
 
+static NORETURN void die_want_option(const char *option_name)
+{
+	die(_("option '%s' requires a value"), option_name);
+}
+
 static int parse_diff_color_slot(const char *var)
 {
 	if (!strcasecmp(var, "context") || !strcasecmp(var, "plain"))
