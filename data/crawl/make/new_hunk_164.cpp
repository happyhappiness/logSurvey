  switch (*funcname)
    {
    case 'e':
      OS (fatal, reading_file, "%s", msg);

    case 'w':
      OS (error, reading_file, "%s", msg);
      break;

    case 'i':
