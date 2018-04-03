 		return 0;
 	}
 
+	if (argc == 4 && !strcmp(argv[1], "relative_path")) {
+		const char *in, *prefix, *rel;
+		normalize_argv_string(&in, argv[2]);
+		normalize_argv_string(&prefix, argv[3]);
+		rel = relative_path(in, prefix);
+		if (!rel)
+			puts("(null)");
+		else
+			puts(strlen(rel) > 0 ? rel : "(empty)");
+		return 0;
+	}
+
 	fprintf(stderr, "%s: unknown function name: %s\n", argv[0],
 		argv[1] ? argv[1] : "(there was none)");
 	return 1;