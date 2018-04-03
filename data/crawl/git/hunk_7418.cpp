 #include "builtin.h"
 #include "exec_cmd.h"
 #include "common-cmds.h"
-
-static const char *help_default_format;
-
-static enum help_format {
-	man_format,
-	info_format,
-	web_format,
-} help_format = man_format;
-
-static void parse_help_format(const char *format)
+#include "parse-options.h"
+
+enum help_format {
+	HELP_FORMAT_MAN,
+	HELP_FORMAT_INFO,
+	HELP_FORMAT_WEB,
+};
+
+static int show_all = 0;
+static enum help_format help_format = HELP_FORMAT_MAN;
+static struct option builtin_help_options[] = {
+	OPT_BOOLEAN('a', "all", &show_all, "print all available commands"),
+	OPT_SET_INT('m', "man", &help_format, "show man page", HELP_FORMAT_MAN),
+	OPT_SET_INT('w', "web", &help_format, "show manual in web browser",
+			HELP_FORMAT_WEB),
+	OPT_SET_INT('i', "info", &help_format, "show info page",
+			HELP_FORMAT_INFO),
+};
+
+static const char * const builtin_help_usage[] = {
+	"git-help [--all] [--man|--web|--info] [command]",
+	NULL
+};
+
+static enum help_format parse_help_format(const char *format)
 {
-	if (!format) {
-		help_format = man_format;
-		return;
-	}
-	if (!strcmp(format, "man")) {
-		help_format = man_format;
-		return;
-	}
-	if (!strcmp(format, "info")) {
-		help_format = info_format;
-		return;
-	}
-	if (!strcmp(format, "web") || !strcmp(format, "html")) {
-		help_format = web_format;
-		return;
-	}
+	if (!strcmp(format, "man"))
+		return HELP_FORMAT_MAN;
+	if (!strcmp(format, "info"))
+		return HELP_FORMAT_INFO;
+	if (!strcmp(format, "web") || !strcmp(format, "html"))
+		return HELP_FORMAT_WEB;
 	die("unrecognized help format '%s'", format);
 }
 
 static int git_help_config(const char *var, const char *value)
 {
-	if (!strcmp(var, "help.format"))
-		return git_config_string(&help_default_format, var, value);
+	if (!strcmp(var, "help.format")) {
+		if (!value)
+			return config_error_nonbool(var);
+		help_format = parse_help_format(value);
+		return 0;
+	}
 	return git_default_config(var, value);
 }
 
