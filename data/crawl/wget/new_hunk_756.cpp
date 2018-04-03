}


/* Basic check of an encoding name. */
bool
check_encoding_name (char *encoding)
{
  char *s = encoding;

  while (*s)
    {
      if (!c_isascii(*s) || c_isspace(*s))
        {
          logprintf (LOG_VERBOSE, "Encoding %s isn't valid\n", quote(encoding));
          return false;
        }

      s++;
    }

  return true;
}


