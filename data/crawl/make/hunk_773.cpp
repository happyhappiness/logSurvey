            of the unparsed section of p2, for later.  */
         if (*lb_next != '\0')
           {
-            unsigned int l = p - variable_buffer;
-            unsigned int l2 = p2 - variable_buffer;
+            unsigned int l = p2 - variable_buffer;
             plen = strlen (p2);
             (void) variable_buffer_output (p2+plen,
                                            lb_next, strlen (lb_next)+1);
-            p = variable_buffer + l;
-            p2 = variable_buffer + l2;
+            p2 = variable_buffer + l;
           }
 
         /* See if it's an "override" or "export" keyword; if so see if what
