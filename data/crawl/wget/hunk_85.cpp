         exit (WGET_EXIT_GENERIC_ERROR);
     }
 
+  if (opt.use_askpass)
+  {
+    if (opt.use_askpass[0] == '\0')
+      {
+        fprintf (stderr,
+                 _("use-askpass requires a string or either environment variable WGET_ASKPASS or SSH_ASKPASS to be set.\n"));
+        exit (WGET_EXIT_GENERIC_ERROR);
+      }
+  }
+
 #ifdef USE_WATT32
   if (opt.wdebug)
      dbug_init();
