  while (n != p);

  p = strlen (keyword) + n + 2;
  x_obstack_blank (&extended_header, p);
  x_obstack_1grow (&extended_header, '\n');
  cp = obstack_next_free (extended_header.stk) - string_length - p - 1;
