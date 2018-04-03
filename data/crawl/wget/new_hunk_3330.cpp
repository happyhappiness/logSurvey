  while (val < end && ISSPACE (end[-1]))
    --end;
  if (val == end)
    return 0;

  if (!simple_atof (val, end, &number))
    return 0;

  *result = number * mult;
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
  double byte_value;
  if (!parse_bytes_helper (val, &byte_value))
    {
      fprintf (stderr, _("%s: %s: Invalid byte value `%s'\n"),
	       exec_name, com, val);
      return 0;
    }
  *(long *)closure = (long)byte_value;
  return 1;
}

/* Like cmd_bytes, but CLOSURE is interpreted as a pointer to
   LARGE_INT.  It works by converting the string to double, therefore
   working with values up to 2^53-1 without loss of precision.  This
   value (8192 TB) is large enough to serve for a while.  */

static int
cmd_bytes_large (const char *com, const char *val, void *closure)
{
  double byte_value;
  if (!parse_bytes_helper (val, &byte_value))
    {
      fprintf (stderr, _("%s: %s: Invalid byte value `%s'\n"),
	       exec_name, com, val);
      return 0;
    }
  *(LARGE_INT *)closure = (LARGE_INT)byte_value;
  return 1;
}

