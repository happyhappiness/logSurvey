 	    {
 	      p2 = next_token (p + 6);
               if (*p2 == '\0')
-                fatal (&fileinfo, "empty variable name");
+                fatal (&fileinfo, _("empty variable name"));
 
 	      /* Let the variable name be the whole rest of the line,
 		 with trailing blanks stripped (comments have already been
