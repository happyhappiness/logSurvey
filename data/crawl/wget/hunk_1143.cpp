   if (val == end)
     {
     err:
-      fprintf (stderr, _("%s: %s: Invalid time period `%s'\n"),
-               exec_name, com, val);
+      fprintf (stderr, _("%s: %s: Invalid time period %s\n"),
+               exec_name, com, quote (val));
       return false;
     }
 
