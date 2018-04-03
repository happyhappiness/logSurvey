 	      else
 		{
 		  p2 = next_token (p2 + 6);
+                  if (*p2 == '\0')
+                    fatal (&fileinfo, "empty variable name");
+
 		  /* Let the variable name be the whole rest of the line,
 		     with trailing blanks stripped (comments have already been
 		     removed), so it could be a complex variable/function
