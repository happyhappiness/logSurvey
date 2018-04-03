  PATH_VAR (pwdbuf);
  char *message = entering ? "Entering" : "Leaving";

  if (entered && entering)
    /* Don't print the leaving message if we
       haven't printed the entering message.  */
    return;
  else
    entered = 1;

  if (print_data_base_flag)
    fputs ("# ", stdout);
