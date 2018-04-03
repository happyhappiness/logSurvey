
static int simple_atof PARAMS ((const char *, const char *, double *));

/* Enginge for cmd_bytes and cmd_bytes_large: converts a string such
   as "100k" or "2.5G" to a floating point number.  */

static int
parse_bytes_helper (const char *val, double *result)
{
  double number, mult;
  const char *end = val + strlen (val);

  /* Check for "inf".  */
  if (0 == strcmp (val, "inf"))
    {
      *result = 0;
      return 1;
    }

  /* Strip trailing whitespace.  */
  while (val < end && ISSPACE (end[-1]))
    --end;
  if (val == end)
    return 0;

  switch (TOLOWER (end[-1]))
    {
    case 'k':
      --end, mult = 1024.0;
      break;
    case 'm':
      --end, mult = 1048576.0;
      break;
    case 'g':
      --end, mult = 1073741824.0;
      break;
    case 't':
      --end, mult = 1099511627776.0;
      break;
    default:
      /* Not a recognized suffix: assume it's a digit.  (If not,
	 simple_atof will raise an error.)  */
      mult = 1;
    }

