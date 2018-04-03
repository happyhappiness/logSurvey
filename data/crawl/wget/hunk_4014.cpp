 	   _wasn't_ specified last time, or the server contains files called
 	   *.orig, -N will be back to not operating correctly with -k. */
 	{
-	  size_t filename_len = strlen(u->local);
-	  char*  filename_plus_orig_suffix = malloc(filename_len +
-						    sizeof(".orig"));
-
 	  /* Would a single s[n]printf() call be faster? */
 	  strcpy(filename_plus_orig_suffix, u->local);
 	  strcpy(filename_plus_orig_suffix + filename_len, ".orig");
