       else
         {
           fprintf (stderr,
-                   _("%s: %s: Invalid restriction `%s', use [unix|windows],[lowercase|uppercase],[nocontrol].\n"),
-                   exec_name, com, val);
+                   _("%s: %s: Invalid restriction %s, use [unix|windows],[lowercase|uppercase],[nocontrol].\n"),
+                   exec_name, com, quote (val));
           return false;
         }
 
