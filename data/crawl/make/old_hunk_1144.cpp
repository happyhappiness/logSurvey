    printf ("%s[%u]: %s ", program, makelevel, msg);

  if (starting_directory == 0)
    puts ("an unknown directory");
  else
    printf ("directory `%s'\n", starting_directory);
}
