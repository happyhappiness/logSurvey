     }
   if (opt.ipv4_only && opt.ipv6_only)
     {
-      if (opt.ipv4_only == -1)
-	/* ipv4_only was set automatically because the system doesn't
-	   support IPv6.  */
-	printf (_("Cannot use --inet6-only on a system without IPv6 support.\n"));
-      else
-	printf (_("Cannot specify both --inet4-only and --inet6-only.\n"));
+      printf (_("Cannot specify both --inet4-only and --inet6-only.\n"));
       print_usage ();
       exit (1);
     }
