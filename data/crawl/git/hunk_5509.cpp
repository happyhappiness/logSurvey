 	}
 
 	if (argc < 4)
-		die("Usage: %s <base>... -- <head> <remote> ...", argv[0]);
+		usagef("%s <base>... -- <head> <remote> ...", argv[0]);
 
 	for (i = 1; i < argc; ++i) {
 		if (!strcmp(argv[i], "--"))