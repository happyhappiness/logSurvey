 	}
 
       if (count >= 0)
-	{
-	  static const char errmsg[]
-	    = "unterminated call to function `%s': missing `%c'";
-	  if (reading_filename == 0)
-	    fatal (errmsg, function_table[code].name, closeparen);
-	  else
-	    makefile_fatal (reading_filename, *reading_lineno_ptr, errmsg,
-			    function_table[code].name, closeparen);
-	}
+        fatal (reading_file,
+               "unterminated call to function `%s': missing `%c'",
+               function_table[code].name, closeparen);
 
       /* We found the end; expand the function call.  */
 
