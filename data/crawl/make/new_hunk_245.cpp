  n = allocated_variable_expand (name);
  name = next_token (n);
  if (name[0] == '\0')
    O (fatal, &defstart, _("empty variable name"));
  p = name + strlen (name) - 1;
  while (p > name && isblank ((unsigned char)*p))
    --p;
