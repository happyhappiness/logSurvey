  return o;
}

static char *
strip_whitespace (const char **begpp, const char **endpp)
{
  while (isspace ((unsigned char)**begpp) && *begpp <= *endpp)
    (*begpp) ++;
  while (isspace ((unsigned char)**endpp) && *endpp >= *begpp)
    (*endpp) --;
  return (char *)*begpp;
}

static void
check_numeric (const char *s, const char *message)
{
  const char *end = s + strlen (s) - 1;
  const char *beg = s;
  strip_whitespace (&s, &end);

  for (; s <= end; ++s)
    if (!ISDIGIT (*s))  /* ISDIGIT only evals its arg once: see make.h.  */
      break;

  if (s <= end || end - beg < 0)
    fatal (reading_file, "%s: '%s'", message, beg);
}


