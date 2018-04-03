 	int output_fd = -1;
 	char *end;
 
-	if (argc < 3)
-		die("URL missing");
+	if (argc != 3)
+		die("Expected two arguments");
 
 	input_fd = (int)strtoul(argv[2], &end, 10);
 
