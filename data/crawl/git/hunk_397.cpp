 	char *end;
 
 	if (argc != 3)
-		die("Expected two arguments");
+		usage(usage_msg);
 
 	input_fd = (int)strtoul(argv[2], &end, 10);
 