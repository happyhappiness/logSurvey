  struct xhdr_tab const *t;

  if (**p == 0)
    return false;

  len = strtoul (*p, p, 10);
  if (**p != ' ')
    {
      ERROR ((0, 0, _("Malformed extended header: missing whitespace after the length")));
      return false;
    }

  keyword = ++*p;
