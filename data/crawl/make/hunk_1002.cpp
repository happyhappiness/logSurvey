          variable output buffer, and skip them.  Uninteresting chars end
 	 at the next $ or the end of the input.  */
 
-      p1 = index (p, '$');
+      p1 = strchr (p, '$');
 
       o = variable_buffer_output (o, p, p1 != 0 ? p1 - p : strlen (p) + 1);
 
