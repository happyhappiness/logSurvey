 	ar_args->time = archive_time;
 }
 
-static void create_output_file(const char *output_file)
-{
-	int output_fd = open(output_file, O_CREAT | O_WRONLY | O_TRUNC, 0666);
-	if (output_fd < 0)
-		die("could not create archive file: %s ", output_file);
-	if (output_fd != 1) {
-		if (dup2(output_fd, 1) < 0)
-			die("could not redirect output");
-		else
-			close(output_fd);
-	}
-}
-
 #define OPT__COMPR(s, v, h, p) \
 	{ OPTION_SET_INT, (s), NULL, (v), NULL, (h), \
 	  PARSE_OPT_NOARG | PARSE_OPT_NONEG, NULL, (p) }
