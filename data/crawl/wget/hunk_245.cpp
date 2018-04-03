       exit (1);
     }
 
+  if (opt.start_pos >= 0 && opt.always_rest)
+    {
+      fprintf (stderr,
+               _("Specifying both --start-pos and --continue is not "
+                 "recommended; --continue will be disabled.\n"));
+      opt.always_rest = false;
+    }
+
   if (!nurl && !opt.input_filename)
     {
       /* No URL specified.  */
