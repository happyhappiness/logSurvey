 	if (!strcmp(var, "diff.ignoresubmodules"))
 		handle_ignore_submodules_arg(&default_diff_options, value);
 
+	if (!strcmp(var, "diff.submodule")) {
+		if (parse_submodule_params(&default_diff_options, value))
+			warning(_("Unknown value for 'diff.submodule' config variable: '%s'"),
+				value);
+		return 0;
+	}
+
 	if (git_color_config(var, value, cb) < 0)
 		return -1;
 
