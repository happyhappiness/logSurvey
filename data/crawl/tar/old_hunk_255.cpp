  struct xhdr_tab const *t;

  if (**p == 0)
    return true;

  len = strtoul (*p, p, 10);
  if (**p != ' ')
    {
      ERROR ((0, 0, _("Malformed extended header")));
      return true;
    }

  keyword = ++*p;
