}

void
check_numeric (char *s, char *message)
{
  if (!is_numeric (s))
    fatal (reading_file, message);
