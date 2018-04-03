  dfd->fab$l_nam->nam$l_rsa = resultspec;
  dfd->fab$l_nam->nam$b_rss = MAXNAMLEN;

  if (debug_flag)
    printf (".");

  if (!((i = sys$search (dfd)) & 1))
    {
      if (debug_flag)
	printf ("sys$search failed with %d\n", i);
      free (dentry);
      return (NULL);
    }
