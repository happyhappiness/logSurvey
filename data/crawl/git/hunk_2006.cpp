 		OPT__VERBOSE(&verbose, "be verbose"),
 		OPT__DRY_RUN(&dry_run, "dry run"),
 		OPT__QUIET(&quiet, "be quiet"),
+		OPT_CALLBACK(0, "expect", &expect, "string",
+			     "expected output in the variable dump",
+			     collect_expect),
 		OPT_END(),
 	};
 	int i;
+	int ret = 0;
 
 	argc = parse_options(argc, (const char **)argv, prefix, options, usage, 0);
 
 	if (length_cb.called) {
 		const char *arg = length_cb.arg;
 		int unset = length_cb.unset;
-		printf("Callback: \"%s\", %d\n",
-		       (arg ? arg : "not set"), unset);
+		show(&expect, &ret, "Callback: \"%s\", %d",
+		     (arg ? arg : "not set"), unset);
 	}
-	printf("boolean: %d\n", boolean);
-	printf("integer: %d\n", integer);
-	printf("magnitude: %lu\n", magnitude);
-	printf("timestamp: %lu\n", timestamp);
-	printf("string: %s\n", string ? string : "(not set)");
-	printf("abbrev: %d\n", abbrev);
-	printf("verbose: %d\n", verbose);
-	printf("quiet: %d\n", quiet);
-	printf("dry run: %s\n", dry_run ? "yes" : "no");
-	printf("file: %s\n", file ? file : "(not set)");
+	show(&expect, &ret, "boolean: %d", boolean);
+	show(&expect, &ret, "integer: %d", integer);
+	show(&expect, &ret, "magnitude: %lu", magnitude);
+	show(&expect, &ret, "timestamp: %lu", timestamp);
+	show(&expect, &ret, "string: %s", string ? string : "(not set)");
+	show(&expect, &ret, "abbrev: %d", abbrev);
+	show(&expect, &ret, "verbose: %d", verbose);
+	show(&expect, &ret, "quiet: %d", quiet);
+	show(&expect, &ret, "dry run: %s", dry_run ? "yes" : "no");
+	show(&expect, &ret, "file: %s", file ? file : "(not set)");
 
 	for (i = 0; i < list.nr; i++)
-		printf("list: %s\n", list.items[i].string);
+		show(&expect, &ret, "list: %s", list.items[i].string);
 
 	for (i = 0; i < argc; i++)
-		printf("arg %02d: %s\n", i, argv[i]);
+		show(&expect, &ret, "arg %02d: %s", i, argv[i]);
 
-	return 0;
+	return ret;
 }