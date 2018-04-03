  current_entry = load_dict (FH);

  while (fgets (line, sizeof (line), stdin)) {
    if ((cp = strchr (line, '\n')) != NULL) {
      *cp = '\0';
    }
    if ((cp = strtok (line, " \t")) != NULL) {
      address = cp;
      username = strtok (NULL, " \t");
    } else {
      fprintf (stderr, "helper: unable to read tokens\n");
      printf ("ERR\n");
      continue;
    }
#ifdef DEBUG
    printf ("result: %d\n",
	    dict_lookup (current_entry, username, address));
#endif
    if ((dict_lookup (current_entry, username, address)) != 0) {
      printf ("OK\n");
    } else {
      printf ("ERR\n");
    }


  }


