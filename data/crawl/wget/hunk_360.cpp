   /* Sanity checks.  */
   if (opt.verbose && opt.quiet)
     {
-      printf (_("Can't be verbose and quiet at the same time.\n"));
-      print_usage ();
+      fprintf (stderr, _("Can't be verbose and quiet at the same time.\n"));
+      print_usage (1);
       exit (1);
     }
   if (opt.timestamping && opt.noclobber)
     {
-      printf (_("\
+      fprintf (stderr, _("\
 Can't timestamp and not clobber old files at the same time.\n"));
-      print_usage ();
+      print_usage (1);
       exit (1);
     }
 #ifdef ENABLE_IPV6
   if (opt.ipv4_only && opt.ipv6_only)
     {
-      printf (_("Cannot specify both --inet4-only and --inet6-only.\n"));
-      print_usage ();
+      fprintf (stderr,
+               _("Cannot specify both --inet4-only and --inet6-only.\n"));
+      print_usage (1);
       exit (1);
     }
 #endif
