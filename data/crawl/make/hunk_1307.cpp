 		  p = index (p2, '\0');
 		  while (isblank (p[-1]))
 		    --p;
-		  lineno = do_define (p2, p - p2, o_override,
-				      lineno, infile, filename);
+		  do_define (p2, p - p2, o_override, infile, &fileinfo);
 		}
 	    }
 	  else if (!ignoring
-		   && !try_variable_definition (filename, lineno,
-						p2, o_override))
-	    makefile_error (filename, lineno, "empty `override' directive");
+		   && !try_variable_definition (&fileinfo, p2, o_override))
+	    error (&fileinfo, "empty `override' directive");
 
 	  continue;
 	}
