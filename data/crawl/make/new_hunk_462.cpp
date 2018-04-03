    return 0;

  if (p[1] == '(' && end[-1] == ')')
    fatal (NILF, _("attempt to use unsupported feature: '%s'"), name);

  return 1;
}
