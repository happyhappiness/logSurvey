   else
     {
       fprintf (stderr,
-               _("%s: %s: Invalid boolean `%s'; use `on' or `off'.\n"),
-               exec_name, com, val);
+               _("%s: %s: Invalid boolean %s; use `on' or `off'.\n"),
+               exec_name, com, quote (val));
       return false;
     }
 
