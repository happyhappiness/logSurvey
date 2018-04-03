
      if (fprintf (fp, "%s\t%d\t%d\t%lu\t%lu\n",
                   kh->host, kh->explicit_port, khi->include_subdomains,
                   (unsigned long) khi->created,
                   (unsigned long) khi->max_age) < 0)
        {
          logprintf (LOG_ALWAYS, "Could not write the HSTS database correctly.\n");
          break;
