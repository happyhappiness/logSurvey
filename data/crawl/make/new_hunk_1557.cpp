  else
    printf ("%s[%u]: %s ", program, makelevel, message);

  if (starting_directory == 0)
    puts ("an unknown directory");
  else
    printf ("directory `%s'\n", starting_directory);
}
