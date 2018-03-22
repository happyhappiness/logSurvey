  errno = 0;
  len = strtoul (p, &len_lim, 10);

  if (len_max < len || (len == ULONG_MAX && errno == ERANGE))
    {
      ERROR ((0, 0, _("Malformed extended header: length out of range")));
      return false;
    }

