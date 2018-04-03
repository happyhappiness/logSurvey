  switch (*funcname)
    {
    case 'e':
      fatal (reading_file, "%s", msg);

    case 'w':
      error (reading_file, "%s", msg);
      break;

    case 'i':
