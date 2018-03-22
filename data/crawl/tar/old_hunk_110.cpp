    }

  errno = 0;
  len = strtoul (p, &len_lim, 10);

  if (len_max < len)
    {
      int len_len = len_lim - p;
