  return 1;
}

/* Store the value of VAL to *OUT, allowing suffixes for minutes and
   hours.  */
static int
cmd_time (const char *com, const char *val, void *closure)
{
  long result = 0;
  const char *p = val;

  /* Search for digits and construct result.  */
  for (; *p && ISDIGIT (*p); p++)
    result = (10 * result) + (*p - '0');
  /* If no digits were found, or more than one character is following
     them, bail out.  */
  if (p == val || (*p != '\0' && *(p + 1) != '\0'))
    {
      printf (_("%s: Invalid specification `%s'\n"), com, val);
      return 0;
    }
  /* Search for a suffix.  */
  switch (TOLOWER (*p))
    {
    case '\0':
      /* None */
      break;
    case 'm':
      /* Minutes */
      result *= 60;
      break;
    case 'h':
      /* Seconds */
      result *= 3600;
      break;
    case 'd':
      /* Days (overflow on 16bit machines) */
      result *= 86400L;
      break;
    case 'w':
      /* Weeks :-) */
      result *= 604800L;
      break;
    default:
      printf (_("%s: Invalid specification `%s'\n"), com, val);
      return 0;
    }
  *(long *)closure = result;
  return 1;
}

