    value = strchr (argv[i], (int)'=');

    if (! value) {
      fprintf (stderr, "ERROR: Invalid option ``%s''.\n", argv[i]);
      return (-1);
    }

