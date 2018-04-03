 		return 0;
 	}
 
+	if (argc == 2 && !strcmp(argv[1], "basename"))
+		return test_function(basename_data, basename, argv[1]);
+
+	if (argc == 2 && !strcmp(argv[1], "dirname"))
+		return test_function(dirname_data, dirname, argv[1]);
+
 	fprintf(stderr, "%s: unknown function name: %s\n", argv[0],
 		argv[1] ? argv[1] : "(there was none)");
 	return 1;