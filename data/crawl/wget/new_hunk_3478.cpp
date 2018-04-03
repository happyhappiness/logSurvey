    {
      char *rewritten = rewrite_shorthand_url (argv[optind]);
      if (rewritten)
	url[i] = rewritten;
      else
	url[i] = xstrdup (argv[optind]);
    }
