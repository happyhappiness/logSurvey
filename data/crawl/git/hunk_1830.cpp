 	if (e) {
 		int v = git_config_maybe_bool(name, e);
 		if (v < 0)
-			die("Bad value '%s' in environment '%s'", e, name);
+			die(_("Bad value '%s' in environment '%s'"), e, name);
 		return v;
 	}
 
