  return o;
}

char *
strip_whitespace (char **begpp, char **endpp)
{
  while (isspace ((unsigned char)**begpp) && *begpp <= *endpp)
    (*begpp) ++;
  while (isspace ((unsigned char)**endpp) && *endpp >= *begpp)
    (*endpp) --;
  return *begpp;
}

int
is_numeric (char *p)
{
  char *end = p + strlen (p) - 1;
  char *beg = p;
  strip_whitespace (&p, &end);

  while (p <= end)
    if (!ISDIGIT (*(p++)))  /* ISDIGIT only evals its arg once: see make.h.  */
      return 0;

  return (end - beg >= 0);
}

void
check_numeric (char *s, char *message)
{
  if (!is_numeric (s))
    fatal (reading_file, message);
}


