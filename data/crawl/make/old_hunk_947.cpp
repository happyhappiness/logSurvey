  dnam->nam$l_rsa = dir->d_result;
  dnam->nam$b_rss = MAXNAMLEN;

  if (debug_flag)
    printf (".");

  if (!((i = sys$search (dfab)) & 1))
    {
      if (debug_flag)
	printf ("sys$search failed with %d\n", i);
      return (NULL);
    }

