 
 	argc = parse_options(argc, (const char **)argv, prefix, options, usage, 0);
 
+	if (length_cb.called) {
+		const char *arg = length_cb.arg;
+		int unset = length_cb.unset;
+		printf("Callback: \"%s\", %d\n",
+		       (arg ? arg : "not set"), unset);
+	}
 	printf("boolean: %d\n", boolean);
 	printf("integer: %d\n", integer);
 	printf("magnitude: %lu\n", magnitude);