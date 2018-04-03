 		die("-x and -X cannot be used together");
 
 	if (!show_only && !force)
-		die("clean.requireForce set and -n or -f not given; refusing to clean");
+		die("clean.requireForce%s set and -n or -f not given; "
+		    "refusing to clean", config_set ? "" : " not");
 
 	dir.show_other_directories = 1;
 