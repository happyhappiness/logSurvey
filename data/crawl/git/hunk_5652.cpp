 	if (!cmit)
 		die("%s is not a valid '%s' object", arg, commit_type);
 
-	if (!initialized) {
-		initialized = 1;
-		for_each_ref(get_name, NULL);
-	}
-
-	if (!found_names)
-		die("cannot describe '%s'", sha1_to_hex(sha1));
-
 	n = cmit->util;
 	if (n) {
 		/*
