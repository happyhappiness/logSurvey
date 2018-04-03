 #include "dir.h"
 #include "refs.h"
 
+enum rebase_type {
+	REBASE_INVALID = -1,
+	REBASE_FALSE = 0,
+	REBASE_TRUE,
+	REBASE_PRESERVE
+};
+
+/**
+ * Parses the value of --rebase. If value is a false value, returns
+ * REBASE_FALSE. If value is a true value, returns REBASE_TRUE. If value is
+ * "preserve", returns REBASE_PRESERVE. If value is a invalid value, dies with
+ * a fatal error if fatal is true, otherwise returns REBASE_INVALID.
+ */
+static enum rebase_type parse_config_rebase(const char *key, const char *value,
+		int fatal)
+{
+	int v = git_config_maybe_bool("pull.rebase", value);
+
+	if (!v)
+		return REBASE_FALSE;
+	else if (v > 0)
+		return REBASE_TRUE;
+	else if (!strcmp(value, "preserve"))
+		return REBASE_PRESERVE;
+
+	if (fatal)
+		die(_("Invalid value for %s: %s"), key, value);
+	else
+		error(_("Invalid value for %s: %s"), key, value);
+
+	return REBASE_INVALID;
+}
+
+/**
+ * Callback for --rebase, which parses arg with parse_config_rebase().
+ */
+static int parse_opt_rebase(const struct option *opt, const char *arg, int unset)
+{
+	enum rebase_type *value = opt->value;
+
+	if (arg)
+		*value = parse_config_rebase("--rebase", arg, 0);
+	else
+		*value = unset ? REBASE_FALSE : REBASE_TRUE;
+	return *value == REBASE_INVALID ? -1 : 0;
+}
+
 static const char * const pull_usage[] = {
 	N_("git pull [options] [<repository> [<refspec>...]]"),
 	NULL
