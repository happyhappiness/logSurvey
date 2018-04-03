                program, makelevel);
    else
      if (entering)
        printf (_("%s[%u]: Entering directory '%s'\n"),
                program, makelevel, starting_directory);
      else
        printf (_("%s[%u]: Leaving directory '%s'\n"),
                program, makelevel, starting_directory);

  /* Flush stdout to be sure this comes before any stderr output.  */
