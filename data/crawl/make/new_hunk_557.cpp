  while (*s != '\0')
    {
      const char *end;
      int bs;

      /* Print one full logical recipe line: find a non-escaped newline.  */
      for (end = s, bs = 0; *end != '\0'; ++end)
        {
          if (*end == '\n' && !bs)
            break;

          bs = *end == '\\' ? !bs : 0;
        }

      printf ("%c%.*s\n", cmd_prefix, (int) (end - s), s);

