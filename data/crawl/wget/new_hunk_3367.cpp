  return 1;
}

/* Poor man's atof: handles only <digits>.<digits>.  Returns 1 on
   success, 0 on failure.  In case of success, stores its result to
   *DEST.  */

static int
simple_atof (const char *beg, const char *end, double *dest)
{
  double result = 0;

  int seen_dot = 0;
  int seen_digit = 0;
  double divider = 1;

  const char *p = beg;

  while (p < end)
    {
      char ch = *p++;
      if (ISDIGIT (ch))
	{
	  if (!seen_dot)
	    result = (10 * result) + (ch - '0');
	  else
	    result += (ch - '0') / (divider *= 10);
	  seen_digit = 1;
	}
      else if (ch == '.')
	{
	  if (!seen_dot)
	    seen_dot = 1;
	  else
	    return 0;
	}
    }
  if (!seen_digit)
    return 0;

  *dest = result;
  return 1;
}

/* Parse VAL as a number and set its value to CLOSURE (which should
   point to a long int).

   By default, the value is assumed to be in bytes.  If "K", "M", or
   "G" are appended, the value is multiplied with 1<<10, 1<<20, or
   1<<30, respectively.  Floating point values are allowed and are
   cast to integer before use.  The idea is to be able to use things
   like 1.5k instead of "1536".

   The string "inf" is returned as 0.

   In case of error, 0 is returned and memory pointed to by CLOSURE
   remains unmodified.  */

static int
cmd_bytes (const char *com, const char *val, void *closure)
{
  long mult;
  double number;
  const char *end = val + strlen (val);

  /* Check for "inf".  */
  if (0 == strcmp (val, "inf"))
    {
      *(long *)closure = 0;
      return 1;
    }

  /* Strip trailing whitespace.  */
  while (val < end && ISSPACE (end[-1]))
    --end;

  if (val == end)
    {
    err:
      fprintf (stderr, _("%s: Invalid byte value `%s'\n"), com, val);
      return 0;
    }

  switch (TOLOWER (end[-1]))
    {
    case 'k':
      --end, mult = 1L<<10;
      break;
    case 'm':
      --end, mult = 1L<<20;
      break;
    case 'g':
      --end, mult = 1L<<30;
      break;
    default:
      /* Not a recognized suffix: assume it belongs to the number.
	 (If not, atof simple_atof will raise an error.)  */
      mult = 1;
    }

  /* Skip leading and trailing whitespace. */
  while (val < end && ISSPACE (*val))
    ++val;
  while (val < end && ISSPACE (end[-1]))
    --end;
  if (val == end)
    goto err;

  if (!simple_atof (val, end, &number))
    goto err;

  *(long *)closure = (long)(number * mult);
  return 1;
}

