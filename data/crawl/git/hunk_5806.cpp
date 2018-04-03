 
 		if (*buf) {
 			if (!*cwd && !getcwd(cwd, sizeof(cwd)))
-				die ("Could not get current working directory");
+				die_errno ("Could not get current working directory");
 
 			if (chdir(buf))
-				die ("Could not switch to '%s'", buf);
+				die_errno ("Could not switch to '%s'", buf);
 		}
 		if (!getcwd(buf, PATH_MAX))
-			die ("Could not get current working directory");
+			die_errno ("Could not get current working directory");
 
 		if (last_elem) {
 			int len = strlen(buf);
