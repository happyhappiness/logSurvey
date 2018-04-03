 	}
 
 	if (!strcmp(var, "core.abbrev")) {
-		int abbrev = git_config_int(var, value);
-		if (abbrev < minimum_abbrev || abbrev > 40)
-			return -1;
-		default_abbrev = abbrev;
+		if (!value)
+			return config_error_nonbool(var);
+		if (!strcasecmp(value, "auto"))
+			default_abbrev = -1;
+		else {
+			int abbrev = git_config_int(var, value);
+			if (abbrev < minimum_abbrev || abbrev > 40)
+				return error("abbrev length out of range: %d", abbrev);
+			default_abbrev = abbrev;
+		}
 		return 0;
 	}
 