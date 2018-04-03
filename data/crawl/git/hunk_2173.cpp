 		int using_default = 0;
 		if (!name) {
 			if (strict && ident_use_config_only
-			    && !(ident_config_given & IDENT_NAME_GIVEN))
-				die("user.useConfigOnly set but no name given");
+			    && !(ident_config_given & IDENT_NAME_GIVEN)) {
+				fputs(env_hint, stderr);
+				die("no name was given and auto-detection is disabled");
+			}
 			name = ident_default_name();
 			using_default = 1;
 			if (strict && default_name_is_bogus) {
