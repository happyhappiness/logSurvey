 	argc = parse_options(argc, (const char **)argv, prefix, options, usage, 0);
 
 	printf("boolean: %d\n", boolean);
-	printf("integer: %u\n", integer);
+	printf("integer: %d\n", integer);
 	printf("timestamp: %lu\n", timestamp);
 	printf("string: %s\n", string ? string : "(not set)");
 	printf("abbrev: %d\n", abbrev);