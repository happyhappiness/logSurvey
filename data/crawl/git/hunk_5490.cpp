 	/* write references */
 	argc = setup_revisions(argc, argv, &revs, NULL);
 
-	for (i = 1; i < argc; i++) {
-		if (!strcmp(argv[i], "--stdin")) {
-			if (read_from_stdin++)
-				die("--stdin given twice?");
-			read_revisions_from_stdin(&revs);
-			continue;
-		}
-		return error("unrecognized argument: %s'", argv[i]);
-	}
+	if (argc > 1)
+		return error("unrecognized argument: %s'", argv[1]);
 
 	object_array_remove_duplicates(&revs.pending);
 
