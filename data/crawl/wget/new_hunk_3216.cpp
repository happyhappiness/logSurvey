    }
  if (opt.ipv4_only && opt.ipv6_only)
    {
      printf (_("Cannot specify both --inet4-only and --inet6-only.\n"));
      print_usage ();
      exit (1);
    }
