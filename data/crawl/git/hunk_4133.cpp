 	argc = setup_revisions(argc, argv, &revs, NULL);
 
 	if (argc > 1)
-		return error("unrecognized argument: %s'", argv[1]);
+		return error("unrecognized argument: %s", argv[1]);
 
 	object_array_remove_duplicates(&revs.pending);
 