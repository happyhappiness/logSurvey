{
  FILE *fp = (FILE *)arg;
  char *domain = (char *)key;
  struct cookie *chain = (struct cookie *)value;
  for (; chain; chain = chain->next)
    {
      if (!chain->permanent)
	continue;
      if (COOKIE_EXPIRED_P (chain))
	continue;
      fputs (domain, fp);
      if (chain->port != PORT_ANY)
	fprintf (fp, ":%d", chain->port);
      fprintf (fp, "\t%s\t%s\t%s\t%.0f\t%s\t%s\n",
	       *domain == '.' ? "TRUE" : "FALSE",
	       chain->path, chain->secure ? "TRUE" : "FALSE",
	       (double)chain->expiry_time,
	       chain->attr, chain->value);
      if (ferror (fp))
	return 1;		/* stop mapping */
    }
