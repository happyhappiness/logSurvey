  return 1;
}

/* Set the value stored in VAL to CLOSURE (which should point to a
   long int), allowing several postfixes, with the following syntax
   (regexp):

   [0-9]+       -> bytes
   [0-9]+[kK]   -> bytes * 1024
   [0-9]+[mM]   -> bytes * 1024 * 1024
   inf          -> 0

   Anything else is flagged as incorrect, and CLOSURE is unchanged.  */
static int
cmd_bytes (const char *com, const char *val, void *closure)
{
  long result;
  long *out = (long *)closure;
  const char *p;

  result = 0;
  p = val;
  /* Check for "inf".  */
  if (p[0] == 'i' && p[1] == 'n' && p[2] == 'f' && p[3] == '\0')
    {
      *out = 0;
      return 1;
    }
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
  /* Search for a designator.  */
  switch (TOLOWER (*p))
    {
    case '\0':
      /* None */
      break;
    case 'k':
      /* Kilobytes */
      result *= 1024;
      break;
    case 'm':
      /* Megabytes */
      result *= (long)1024 * 1024;
      break;
    case 'g':
      /* Gigabytes */
      result *= (long)1024 * 1024 * 1024;
      break;
    default:
      printf (_("%s: Invalid specification `%s'\n"), com, val);
      return 0;
    }
  *out = result;
  return 1;
}

