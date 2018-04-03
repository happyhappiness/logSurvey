    printf ("define %s\n%s\nendef\n", v->name, v->value);
  else
    {
      char *p;

      printf ("%s %s= ", v->name, v->recursive ? v->append ? "+" : "" : ":");

