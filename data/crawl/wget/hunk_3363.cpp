   if (val == end)
     {
     err:
-      fprintf (stderr, _("%s: Invalid time specification `%s'\n"), com, val);
+      fprintf (stderr, _("%s: %s: Invalid time period `%s'\n"),
+	       exec_name, com, val);
       return 0;
     }
 
