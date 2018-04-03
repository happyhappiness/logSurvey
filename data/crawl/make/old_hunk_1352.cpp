      return 0;
    *ap = '\0';

    if (unixy_shell)
      new_argv = construct_command_argv_internal (new_line, (char **) NULL,
                                                  (char *) 0, (char *) 0);
#ifdef  __MSDOS__
    else
      {
