           {
             unsigned int l = p2 - variable_buffer;
             plen = strlen (p2);
-            (void) variable_buffer_output (p2+plen,
-                                           lb_next, strlen (lb_next)+1);
+            variable_buffer_output (p2+plen, lb_next, strlen (lb_next)+1);
             p2 = variable_buffer + l;
           }
 
         /* See if it's an "override" or "export" keyword; if so see if what
            comes after it looks like a variable definition.  */
 
-        wtype = get_next_mword (p2, NULL, &p, &len);
+        wtype = get_next_mword (p2, NULL, &p, &wlen);
 
         v_origin = o_file;
         exported = 0;
