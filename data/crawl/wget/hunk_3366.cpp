      junk to the server.  */
   if (!*val || strchr (val, '\n'))
     {
-      fprintf (stderr, _("%s: %s: Invalid specification `%s'.\n"),
+      fprintf (stderr, _("%s: %s: Invalid value `%s'.\n"),
 	       exec_name, com, val);
       return 0;
     }
