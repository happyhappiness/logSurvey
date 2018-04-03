 
   /* Fill in the arguments.  */
   url = alloca_array (char *, nurl + 1);
+  if (url == NULL)
+    {
+      fprintf (stderr, _("Memory allocation problem\n"));
+      exit (2);
+    }
   for (i = 0; i < nurl; i++, optind++)
     {
       char *rewritten = rewrite_shorthand_url (argv[optind]);
