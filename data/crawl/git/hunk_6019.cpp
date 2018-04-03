 	printf("verbose: %d\n", verbose);
 	printf("quiet: %s\n", quiet ? "yes" : "no");
 	printf("dry run: %s\n", dry_run ? "yes" : "no");
+	printf("file: %s\n", file ? file : "(not set)");
 
 	for (i = 0; i < argc; i++)
 		printf("arg %02d: %s\n", i, argv[i]);