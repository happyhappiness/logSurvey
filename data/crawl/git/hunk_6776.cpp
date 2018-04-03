 			printf("rm '%s'\n", path);
 
 		if (remove_file_from_cache(path))
-			die("git-rm: unable to remove %s", path);
+			die("git rm: unable to remove %s", path);
 	}
 
 	if (show_only)
