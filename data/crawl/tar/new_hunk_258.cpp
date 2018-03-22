
  if (**p != '=')
    {
      ERROR ((0, 0, _("Malformed extended header")));
      return true;
    }

  eqp = *p;
