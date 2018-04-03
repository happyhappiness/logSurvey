      username = strtok (NULL, " \t");
    } else {
      fprintf (stderr, "helper: unable to read tokens\n");
    }
#ifdef DEBUG
    printf ("result: %d\n",
