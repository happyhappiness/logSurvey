  return NULL;
}

static int
decode_record (char **p, struct tar_stat_info *st)
{
  size_t len;
  char *keyword, *eqp;
  char *start = *p;
  struct xhdr_tab *t;

  if (**p == 0)
    return 1;
  
  len = strtoul (*p, p, 10);
  if (**p != ' ')
    {
      ERROR ((0, 0, _("Malformed extended headed")));
      return 1;
    }
  
  keyword = ++*p;
  for (;*p < start + len; ++*p)
    if (**p == '=')
