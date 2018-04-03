  hs->temporary = opt.delete_after || opt.spider || !acceptable (hs->local_file);
  if (hs->temporary)
    {
      char *tmp = NULL;
      asprintf (&tmp, "%s.tmp", hs->local_file);
      xfree (hs->local_file);
      hs->local_file = tmp;
    }
