  return 1;
}

/* Store the value of VAL to *OUT.  The value is a time period, by
   default expressed in seconds.  */

static int
cmd_time (const char *com, const char *val, void *closure)
{
  double result, mult, divider;
  int seen_dot, seen_digit;

  const char *p;
  const char *end = val + strlen (val);

  /* Skip trailing whitespace.  */
  while (end > val && ISSPACE (end[-1]))
    --end;

  if (val == end)
    {
    err:
      fprintf (stderr, _("%s: Invalid time specification `%s'\n"), com, val);
      return 0;
    }

  switch (TOLOWER (end[-1]))
    {
    case 's':
      --end, mult = 1;		/* seconds */
      break;
    case 'm':
      --end, mult = 60;		/* minutes */
      break;
    case 'h':
      --end, mult = 3600;	/* hours */
      break;
    case 'd':
      --end, mult = 86400;	/* days */
      break;
    case 'w':
      --end, mult = 604800;	/* weeks */
      break;
    default:
      /* Not a recognized suffix: treat it as part of number, and
	 assume seconds. */
      mult = 1;
    }

  /* Skip leading and trailing whitespace. */
  while (val < end && ISSPACE (*val))
    ++val;
  while (val > end && ISSPACE (end[-1]))
    --end;
  if (val == end)
    goto err;

  /* Poor man's strtod: */
  result = 0;
  seen_dot = seen_digit = 0;
  divider = 1;

  p = val;
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
	    goto err;
	}
    }
  if (!seen_digit)
    goto err;
  result *= mult;
  *(double *)closure = result;
  return 1;
}

