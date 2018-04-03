  if (makelevel == 0)
    if (starting_directory == 0)
      if (entering)
        printf (_("%s: Entering an unknown directory"), program);
      else
        printf (_("%s: Leaving an unknown directory"), program);
    else
      if (entering)
        printf (_("%s: Entering directory `%s'\n"),
