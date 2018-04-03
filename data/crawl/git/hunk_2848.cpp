 	}
 }
 
-int parse_submodule_config_option(const char *var, const char *value)
-{
-	const char *name, *key;
-	int namelen;
-
-	if (parse_config_key(var, "submodule", &name, &namelen, &key) < 0 || !name)
-		return 0;
-
-	if (!strcmp(key, "path")) {
-		if (!value)
-			return config_error_nonbool(var);
-
-		set_name_for_path(value, name, namelen);
-
-	} else if (!strcmp(key, "fetchrecursesubmodules")) {
-		int fetch_recurse = parse_fetch_recurse_submodules_arg(var, value);
-
-		set_fetch_recurse_for_name(name, namelen, fetch_recurse);
-
-	} else if (!strcmp(key, "ignore")) {
-
-		if (!value)
-			return config_error_nonbool(var);
-
-		if (strcmp(value, "untracked") && strcmp(value, "dirty") &&
-		    strcmp(value, "all") && strcmp(value, "none")) {
-			warning("Invalid parameter \"%s\" for config option \"submodule.%s.ignore\"", value, var);
-			return 0;
-		}
-
-		set_ignore_for_name(name, namelen, value);
-		return 0;
-	}
-	return 0;
-}
-
 void handle_ignore_submodules_arg(struct diff_options *diffopt,
 				  const char *arg)
 {
