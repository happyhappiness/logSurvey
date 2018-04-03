       if (doneany)
 	/* Kill the last space.  */
 	--o;
-      
+
       free (text);
       break;
-      
+
     case function_wildcard:
       text = expand_argument (text, end);
-      
+
       p = string_glob (text);
       o = variable_buffer_output (o, p, strlen (p));
-      
+
       free (text);
       break;
-      
+
     case function_subst:
       /* Get three comma-separated arguments and expand each one.  */
       count = 0;
