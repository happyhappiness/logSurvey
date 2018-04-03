 	if (strict_paths && (!ok_paths || !*ok_paths))
 		die("option --strict-paths requires a whitelist");
 
-	if (base_path) {
-		struct stat st;
-
-		if (stat(base_path, &st) || !S_ISDIR(st.st_mode))
-			die("base-path '%s' does not exist or "
-			    "is not a directory", base_path);
-	}
+	if (base_path && !is_directory(base_path))
+		die("base-path '%s' does not exist or is not a directory",
+		    base_path);
 
 	if (inetd_mode) {
 		struct sockaddr_storage ss;
