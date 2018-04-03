  switch (errno)
    {
    case ENOENT:
      error (NILF, "%s: Command not found", argv[0]);
      break;
    case ENOEXEC:
      {
