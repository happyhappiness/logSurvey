 {
 	if (!strcmp(var, "user.signingkey")) {
 		if (!value)
-			die("user.signingkey without value");
+			return config_error_nonbool(value);
 		set_signingkey(value);
 		return 0;
 	}