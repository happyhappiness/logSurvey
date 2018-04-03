  fputs (prefix, stdout);

  /* Is this a `define'?  */
  if (v->recursive && index (v->value, '\n') != 0)
    printf ("define %s\n%s\nendef\n", v->name, v->value);
  else
    {
