  len = strtoul (*p, p, 10);
  if (**p != ' ')
    {
      ERROR ((0, 0, _("Malformed extended header: missing whitespace after the length")));
      return false;
    }

