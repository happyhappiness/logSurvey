    {
      /* Skip if we have a target and this isn't it.  */
      if (target && a->host && strcmp (target, a->host))
	{
	  a = a->next;
	  continue;
	}

      if (!target)
	{
	  /* Print the host name if we have no target.  */
	  if (a->host)
	    fputs (a->host, stdout);
	  else
	    fputs ("DEFAULT", stdout);

	  fputc (' ', stdout);
	}

      /* Print the account name.  */
      fputs (a->acc, stdout);

      if (a->passwd)
	{
	  /* Print the password, if there is any.  */
	  fputc (' ', stdout);
	  fputs (a->passwd, stdout);
	}

      fputc ('\n', stdout);

      /* Exit if we found the target.  */
      if (target)
	exit (0);
      a = a->next;
    }

