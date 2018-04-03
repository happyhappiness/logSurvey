 	}
 	if (!strcmp(var, "format.suffix")) {
 		if (!value)
-			die("format.suffix without value");
+			return config_error_nonbool(var);
 		fmt_patch_suffix = xstrdup(value);
 		return 0;
 	}
 	if (!strcmp(var, "diff.color") || !strcmp(var, "color.diff")) {
 		return 0;
 	}
 	if (!strcmp(var, "format.numbered")) {
-		if (!strcasecmp(value, "auto")) {
+		if (value && !strcasecmp(value, "auto")) {
 			auto_number = 1;
 			return 0;
 		}
-
 		numbered = git_config_bool(var, value);
 		return 0;
 	}