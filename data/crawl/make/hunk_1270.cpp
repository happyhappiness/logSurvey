 
       for (p2 = text; *p2 != '\0'; ++p2)
 	if (*p2 < '0' || *p2 > '9')
-	  {
-	    if (reading_filename != 0)
-	      makefile_fatal (reading_filename, *reading_lineno_ptr,
-			      "non-numeric second argument to `wordlist' function");
-	    else
-	      fatal ("non-numeric second argument to `wordlist' function");
-	  }
+          fatal (reading_file,
+                 "non-numeric second argument to `wordlist' function");
       j = (unsigned int)atoi(text);
       free (text);
 
