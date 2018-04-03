    {
      fprintf (stderr, _("%s: %s: Invalid byte value `%s'\n"),
	       exec_name, com, val);
      return 0;
    }
  *(LARGE_INT *)place = (LARGE_INT)byte_value;
  return 1;
}

/* Store the value of VAL to *OUT.  The value is a time period, by
   default expressed in seconds, but also accepting suffixes "m", "h",
   "d", and "w" for minutes, hours, days, and weeks respectively.  */

static int
cmd_time (const char *com, const char *val, void *place)
{
  double number, mult;
