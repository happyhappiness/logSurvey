  dfd->fab$l_nam->nam$l_rsa = resultspec;
  dfd->fab$l_nam->nam$b_rss = MAXNAMLEN;

  DB (DB_EXTRA, ("."));

  if (!((i = sys$search (dfd)) & 1))
    {
      DB (DB_EXTRA, ("sys$search failed with %d\n", i));
      free (dentry);
      return (NULL);
    }
