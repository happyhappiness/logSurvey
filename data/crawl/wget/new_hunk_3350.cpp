{
  FILE *fp = (FILE *)arg;
  char *domain = (char *)key;
  struct cookie *cookie = (struct cookie *)value;
  for (; cookie; cookie = cookie->next)
    {
      if (!cookie->permanent)
	continue;
      if (COOKIE_EXPIRED_P (cookie))
	continue;
      if (!cookie->domain_exact)
	fputc ('.', fp);
      fputs (domain, fp);
      if (cookie->port != PORT_ANY)
	fprintf (fp, ":%d", cookie->port);
      fprintf (fp, "\t%s\t%s\t%s\t%.0f\t%s\t%s\n",
	       cookie->domain_exact ? "FALSE" : "TRUE",
	       cookie->path, cookie->secure ? "TRUE" : "FALSE",
	       (double)cookie->expiry_time,
	       cookie->attr, cookie->value);
      if (ferror (fp))
	return 1;		/* stop mapping */
    }
