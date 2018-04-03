    fputs ("# ", stdout);

  if (makelevel == 0)
    printf ("%s: %s ", program, msg);
  else
    printf ("%s[%u]: %s ", program, makelevel, msg);

  if (starting_directory == 0)
    puts ("an unknown directory");
