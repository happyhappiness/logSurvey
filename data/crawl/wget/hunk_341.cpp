 prompt_for_password (void)
 {
   if (opt.user)
-    printf (_("Password for user %s: "), quote (opt.user));
+    fprintf (stderr, _("Password for user %s: "), quote (opt.user));
   else
-    printf (_("Password: "));
+    fprintf (stderr, _("Password: "));
   return getpass("");
 }
 
