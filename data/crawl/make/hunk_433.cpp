   const char *path = 0;
   int doneany = 0;
   unsigned int len = 0;
-  struct stat st;
-  PATH_VAR (in);
-  PATH_VAR (out);
 
   while ((path = find_next_token (&p, &len)) != 0)
     {
       if (len < GET_PATH_MAX)
         {
+          char *rp;
+          struct stat st;
+          PATH_VAR (in);
+          PATH_VAR (out);
+
           strncpy (in, path, len);
           in[len] = '\0';
 
-          if (
 #ifdef HAVE_REALPATH
-              realpath (in, out)
+          ENULLLOOP (rp, realpath (in, out));
 #else
-              abspath (in, out)
+          rp = abspath (in, out);
 #endif
-              && stat (out, &st) == 0)
+
+          if (rp)
             {
-              o = variable_buffer_output (o, out, strlen (out));
-              o = variable_buffer_output (o, " ", 1);
-              doneany = 1;
+              int r;
+              EINTRLOOP (r, stat (out, &st));
+              if (r == 0)
+                {
+                  o = variable_buffer_output (o, out, strlen (out));
+                  o = variable_buffer_output (o, " ", 1);
+                  doneany = 1;
+                }
             }
         }
     }
