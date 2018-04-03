 
 int cmd_remote_ext(int argc, const char **argv, const char *prefix)
 {
-	if (argc < 3) {
-		fprintf(stderr, "Error: URL missing");
-		exit(1);
-	}
+	if (argc != 3)
+		die("Expected two arguments");
 
 	return command_loop(argv[2]);
 }
