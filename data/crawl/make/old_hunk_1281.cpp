  switch (errno)
    {
    case ENOENT:
      error ("%s: Command not found", argv[0]);
      break;
    case ENOEXEC:
      {
