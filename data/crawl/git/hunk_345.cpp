 	}
 }
 
+int parse_submodule_fetchjobs(const char *var, const char *value)
+{
+	int fetchjobs = git_config_int(var, value);
+	if (fetchjobs < 0)
+		die(_("negative values not allowed for submodule.fetchjobs"));
+	return fetchjobs;
+}
+
 int parse_fetch_recurse_submodules_arg(const char *opt, const char *arg)
 {
 	return parse_fetch_recurse(opt, arg, 1);
