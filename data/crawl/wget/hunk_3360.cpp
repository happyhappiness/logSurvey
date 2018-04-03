 {
   int lockable_boolean_value;
 
+  int oldval = *(int *)closure;
+
   /*
    * If a config file said "always" or "never", don't allow command line
    * arguments to override the config file.
    */
-  if (*(int *)closure == -1 || *(int *)closure == 2)
+  if (oldval == -1 || oldval == 2)
     return 1;
 
-  if (!strcasecmp (val, "always") || !strcmp (val, "2"))
+  if (0 == strcasecmp (val, "always") || CMP1 (val, '2'))
     lockable_boolean_value = 2;
-  else if (!strcasecmp (val, "on")
-	   || !strcasecmp (val, "yes")
-	   || !strcmp (val, "1"))
+  else if (CMP2 (val, 'o', 'n') || CMP3 (val, 'y', 'e', 's') || CMP1 (val, '1'))
     lockable_boolean_value = 1;
-  else if (!strcasecmp (val, "off")
-	   || !strcasecmp (val, "no")
-	   || !strcmp (val, "0"))
+  else if (CMP3 (val, 'o', 'f', 'f') || CMP2 (val, 'n', 'o') || CMP1 (val, '0'))
     lockable_boolean_value = 0;
-  else if (!strcasecmp (val, "never") || !strcmp (val, "-1"))
+  else if (0 == strcasecmp (val, "never") || CMP2 (val, '-', '1'))
     lockable_boolean_value = -1;
   else
     {
-      fprintf (stderr, _("%s: %s: Please specify always, on, off, "
-			 "or never.\n"),
-	       exec_name, com);
+      fprintf (stderr,
+	       _("%s: %s: Invalid boolean `%s', use always, on, off, or never.\n"),
+	       exec_name, com, val);
       return 0;
     }
 
