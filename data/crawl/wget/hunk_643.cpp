 
   while (*s)
     {
-      if (!c_isascii(*s) || c_isspace(*s))
+      if (!c_isascii (*s) || c_isspace (*s))
         {
-          logprintf (LOG_VERBOSE, "Encoding %s isn't valid\n", quote(encoding));
+          logprintf (LOG_VERBOSE, "Encoding %s isn't valid\n", quote (encoding));
           return false;
         }
 
