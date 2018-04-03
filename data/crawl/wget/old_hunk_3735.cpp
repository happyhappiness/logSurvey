      ++ndot;
      if (ndot == opt.dots_in_line)
	{
	  ndot = 0;
	  ++nrow;
	  if (expected)
	    print_percentage (nrow * line_bytes, expected);
	  logprintf (LOG_VERBOSE, "\n%5ldK ->", nrow * line_bytes / 1024);
	}
    }
  /* Reenable flushing.  */
