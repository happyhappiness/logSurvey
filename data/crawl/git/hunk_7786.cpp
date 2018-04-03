 		int slot = parse_status_slot(k, 13);
 		color_parse(v, k, wt_status_colors[slot]);
 	}
-	if (!strcmp(k, "core.excludesfile")) {
-		if (!v)
-			die("core.excludesfile without value");
-		excludes_file = xstrdup(v);
-		return 0;
-	}
 	return git_default_config(k, v);
 }