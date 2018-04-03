    {
      register char *p;

      printf ("%s %s= ", v->name, v->recursive ? "" : ":");

      /* Check if the value is just whitespace.  */
      p = next_token (v->value);
