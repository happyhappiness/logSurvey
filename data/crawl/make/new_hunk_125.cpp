
  if (*fname == 0)
    printf (_("Warning: Empty redirection\n"));
  if (saved=='\0')
    return ibuf;
  *ibuf = saved;
  return --ibuf;
}


