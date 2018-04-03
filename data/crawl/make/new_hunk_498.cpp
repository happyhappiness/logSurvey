        printf (_("%s: Leaving an unknown directory\n"), program);
    else
      if (entering)
        printf (_("%s: Entering directory '%s'\n"),
                program, starting_directory);
      else
        printf (_("%s: Leaving directory '%s'\n"),
                program, starting_directory);
  else
    if (starting_directory == 0)
