 	++p;
     }
 
-  if (save_char)
-    string[length] = save_char;
+  if (abuf)
+    free (abuf);
 
-  (void)variable_buffer_output (o, "", 1);
+  variable_buffer_output (o, "", 1);
   return (variable_buffer + line_offset);
 }
 
