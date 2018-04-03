  switch (errno)
    {
    case ENOENT:
      OS (error, NILF, _("%s: Command not found"), argv[0]);
      break;
    case ENOEXEC:
      {
