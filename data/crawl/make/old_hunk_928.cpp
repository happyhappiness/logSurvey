  if (v == 0 || *v->value == '\0')
    return o;

  value = (v->recursive ? recursively_expand_setlist (v, setlist) : v->value);

  o = variable_buffer_output (o, value, strlen (value));

