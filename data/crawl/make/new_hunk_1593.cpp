  PATH_VAR (pwdbuf);
  char *message = entering ? "Entering" : "Leaving";

  if (entering)
    entered = 1;
  else if (!entered)
    /* Don't print the leaving message if we
       haven't printed the entering message.  */
    return;

  if (print_data_base_flag)
    fputs ("# ", stdout);
