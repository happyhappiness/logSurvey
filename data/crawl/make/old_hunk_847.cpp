  if (print_data_base_flag)
    fputs ("# ", stdout);

  if (makelevel == 0)
    printf ("%s: ", program);
  else
    printf ("%s[%u]: ", program, makelevel);

  /* Use entire sentences to give the translators a fighting chance.  */

  if (starting_directory == 0)
    if (entering)
      puts (_("Entering an unknown directory"));
    else
      puts (_("Leaving an unknown directory"));
  else
    if (entering)
      printf (_("Entering directory `%s'\n"), starting_directory);
    else
      printf (_("Leaving directory `%s'\n"), starting_directory);
}
