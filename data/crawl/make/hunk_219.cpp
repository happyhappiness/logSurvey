   if (!goals)
     {
       if (read_files == 0)
-        fatal (NILF, _("No targets specified and no makefile found"));
+        O (fatal, NILF, _("No targets specified and no makefile found"));
 
-      fatal (NILF, _("No targets"));
+      O (fatal, NILF, _("No targets"));
     }
 
   /* Update the goals.  */
