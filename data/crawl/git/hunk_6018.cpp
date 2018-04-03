 	};
 	int i;
 
-	argc = parse_options(argc, argv, NULL, options, usage, 0);
+	argc = parse_options(argc, argv, prefix, options, usage, 0);
 
 	printf("boolean: %d\n", boolean);
 	printf("integer: %u\n", integer);
