 		return 0;
 	}
 
+	if (argc == 4 && !strcmp(argv[1], "filter")) {
+		/*
+		 * Retain only the items that have the specified prefix.
+		 * Arguments: list|- prefix
+		 */
+		struct string_list list = STRING_LIST_INIT_DUP;
+		const char *prefix = argv[3];
+
+		parse_string_list(&list, argv[2]);
+		filter_string_list(&list, 0, prefix_cb, (void *)prefix);
+		write_list_compact(&list);
+		string_list_clear(&list, 0);
+		return 0;
+	}
+
 	fprintf(stderr, "%s: unknown function name: %s\n", argv[0],
 		argv[1] ? argv[1] : "(there was none)");
 	return 1;