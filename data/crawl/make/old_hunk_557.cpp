  while (*s != '\0')
    {
      const char *end;

      end = strchr (s, '\n');
      if (end == 0)
	end = s + strlen (s);

      printf ("%c%.*s\n", cmd_prefix, (int) (end - s), s);

