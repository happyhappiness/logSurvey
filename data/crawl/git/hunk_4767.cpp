 		die("bad --ignore-submodules argument: %s", arg);
 }
 
+int parse_fetch_recurse_submodules_arg(const char *opt, const char *arg)
+{
+	switch (git_config_maybe_bool(opt, arg)) {
+	case 1:
+		return RECURSE_SUBMODULES_ON;
+	case 0:
+		return RECURSE_SUBMODULES_OFF;
+	default:
+		if (!strcmp(arg, "on-demand"))
+			return RECURSE_SUBMODULES_ON_DEMAND;
+		die("bad %s argument: %s", opt, arg);
+	}
+}
+
 void show_submodule_summary(FILE *f, const char *path,
 		unsigned char one[20], unsigned char two[20],
 		unsigned dirty_submodule,
