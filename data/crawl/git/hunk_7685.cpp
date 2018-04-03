 	if (!*name) {
 		struct passwd *pw;
 
-		if (0 <= error_on_no_name &&
+		if ((warn_on_no_name || error_on_no_name) &&
 		    name == git_default_name && env_hint) {
 			fprintf(stderr, env_hint, au_env, co_env);
 			env_hint = NULL; /* warn only once, for "git-var -l" */
 		}
-		if (0 < error_on_no_name)
+		if (error_on_no_name)
 			die("empty ident %s <%s> not allowed", name, email);
 		pw = getpwuid(getuid());
 		if (!pw)
