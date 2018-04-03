 			argc--;
 			argv++;
 		}
+		return 0;
 	}
 
 	if (argc == 4 && !strcmp(argv[1], "longest_ancestor_length")) {
 		int len = longest_ancestor_length(argv[2], argv[3]);
 		printf("%d\n", len);
+		return 0;
 	}
 
-	return 0;
+	fprintf(stderr, "%s: unknown function name: %s\n", argv[0],
+		argv[1] ? argv[1] : "(there was none)");
+	return 1;
 }