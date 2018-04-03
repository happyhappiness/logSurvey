  switch (errno)
    {
    case ENOENT:
      /* We are in the child: don't use the output buffer.
         It's not right to run fprintf() here!  */
      if (makelevel == 0)
        fprintf (stderr, _("%s: %s: Command not found\n"), program, argv[0]);
      else
        fprintf (stderr, _("%s[%u]: %s: Command not found\n"),
                 program, makelevel, argv[0]);
      break;
    case ENOEXEC:
      {
