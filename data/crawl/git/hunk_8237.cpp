 	if (!strcmp(var, "diff.color") || !strcmp(var, "color.diff")) {
 		return 0;
 	}
-	if (!strcmp(var, "format.subjectprefix")) {
-		if (!value)
-			die("format.subjectprefix without value");
-		fmt_patch_subject_prefix = xstrdup(value);
-		return 0;
-	}
 
 	return git_log_config(var, value);
 }