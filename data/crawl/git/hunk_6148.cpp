 		die("clean.requireForce%s set and -n or -f not given; "
 		    "refusing to clean", config_set ? "" : " not");
 
-	dir.show_other_directories = 1;
+	dir.flags |= DIR_SHOW_OTHER_DIRECTORIES;
 
 	if (!ignored)
 		setup_standard_excludes(&dir);
