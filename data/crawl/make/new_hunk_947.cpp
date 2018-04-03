  dnam->nam$l_rsa = dir->d_result;
  dnam->nam$b_rss = MAXNAMLEN;

  DB (DB_VERBOSE, ("."));

  if (!((i = sys$search (dfab)) & 1))
    {
      DB (DB_VERBOSE, (_("sys$search failed with %d\n"), i));
      return (NULL);
    }

