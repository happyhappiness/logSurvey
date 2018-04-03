 		die("index file corrupt");
 
 	if (dir.ignored_nr) {
-		fprintf(stderr, ignore_warning);
+		fprintf(stderr, ignore_error);
 		for (i = 0; i < dir.ignored_nr; i++) {
 			fprintf(stderr, "%s\n", dir.ignored[i]->name);
 		}
 		fprintf(stderr, "Use -f if you really want to add them.\n");
-		exit(1);
+		die("no files added");
 	}
 
 	for (i = 0; i < dir.nr; i++)