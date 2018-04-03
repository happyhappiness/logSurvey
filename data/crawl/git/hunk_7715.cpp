 
 		a = strstr(use_message_buffer, "\nauthor ");
 		if (!a)
-			die("invalid commit: %s\n", use_message);
+			die("invalid commit: %s", use_message);
 
 		lb = strstr(a + 8, " <");
 		rb = strstr(a + 8, "> ");
 		eol = strchr(a + 8, '\n');
 		if (!lb || !rb || !eol)
-			die("invalid commit: %s\n", use_message);
+			die("invalid commit: %s", use_message);
 
 		name = xstrndup(a + 8, lb - (a + 8));
 		email = xstrndup(lb + 2, rb - (lb + 2));
