 static int
 cmd_spec_useragent (const char *com, const char *val, void *place_ignored)
 {
-  /* Just check for empty string and newline, so we don't throw total
-     junk to the server.  */
-  if (!*val || strchr (val, '\n'))
+  /* Disallow embedded newlines.  */
+  if (strchr (val, '\n'))
     {
       fprintf (stderr, _("%s: %s: Invalid value `%s'.\n"),
 	       exec_name, com, val);
