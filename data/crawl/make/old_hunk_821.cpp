}

void
check_numeric (s, message)
     char *s;
     char *message;
{
  if (!is_numeric (s))
    fatal (reading_file, message);
