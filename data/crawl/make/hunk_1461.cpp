       p = find_next_token (&p2, &i);
       if (p != 0)
 	o = variable_buffer_output (o, p, i);
-      
+
       free (text);
       break;
-      
+
     case function_word:
       /* Get two comma-separated arguments and expand each one.  */
       count = 0;
