 
   /* Copy its value into the output buffer without expanding it.  */
   if (v)
-    o = variable_buffer_output (o, v->value, strlen(v->value));
+    o = variable_buffer_output (o, v->value, strlen (v->value));
 
   return o;
 }
