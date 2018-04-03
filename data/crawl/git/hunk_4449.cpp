 	dir.flags |= DIR_SHOW_OTHER_DIRECTORIES;
 
 	if (read_cache() < 0)
-		die("index file corrupt");
+		die(_("index file corrupt"));
 
 	if (!ignored)
 		setup_standard_excludes(&dir);
