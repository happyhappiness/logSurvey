    {
      char *rewritten = rewrite_shorthand_url (argv[optind]);
      if (rewritten)
	{
	  printf ("Converted %s to %s\n", argv[optind], rewritten);
	  url[i] = rewritten;
	}
      else
	url[i] = xstrdup (argv[optind]);
    }
