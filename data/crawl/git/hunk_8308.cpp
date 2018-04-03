 	val = read_var(argv[1]);
 	if (!val)
 		usage(var_usage);
-	
+
 	printf("%s\n", val);
-	
+
 	return 0;
 }
