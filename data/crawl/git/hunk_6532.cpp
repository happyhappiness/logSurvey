 		dir = guess_dir_name(repo_name, is_bundle, option_bare);
 	strip_trailing_slashes(dir);
 
-	if (!stat(dir, &buf))
-		die("destination directory '%s' already exists.", dir);
+	dest_exists = !stat(dir, &buf);
+	if (dest_exists && !is_empty_dir(dir))
+		die("destination path '%s' already exists and is not "
+			"an empty directory.", dir);
 
 	strbuf_addf(&reflog_msg, "clone: from %s", repo);
 
