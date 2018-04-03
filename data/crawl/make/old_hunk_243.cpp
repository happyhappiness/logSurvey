  var = allocated_variable_expand (name);
  name = next_token (var);
  if (*name == '\0')
    fatal (&ebuf->floc, _("empty variable name"));
  p = name + strlen (name) - 1;
  while (p > name && isblank ((unsigned char)*p))
    --p;
