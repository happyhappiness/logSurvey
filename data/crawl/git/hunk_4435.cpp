 		if (value && strcmp(value, "now")) {
 			unsigned long now = approxidate("now");
 			if (approxidate(value) >= now)
-				return error("Invalid %s: '%s'", var, value);
+				return error(_("Invalid %s: '%s'"), var, value);
 		}
 		return git_config_string(&prune_expire, var, value);
 	}
