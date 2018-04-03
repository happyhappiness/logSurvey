           strncpy (in, path, len);
           in[len] = '\0';
 
-          if
-          (
+          if (
 #ifdef HAVE_REALPATH
-            realpath (in, out)
+              realpath (in, out)
 #else
-            abspath (in, out)
+              abspath (in, out)
 #endif
-          )
+             )
             {
               o = variable_buffer_output (o, out, strlen (out));
               o = variable_buffer_output (o, " ", 1);
