
/* Store the boolean value from VAL to PLACE.  COM is ignored,
   except for error messages.  */
static int
cmd_boolean (const char *com, const char *val, void *place)
{
  int bool_value;

  if (CMP2 (val, 'o', 'n') || CMP3 (val, 'y', 'e', 's') || CMP1 (val, '1'))
    /* "on", "yes" and "1" mean true. */
    bool_value = 1;
  else if (CMP3 (val, 'o', 'f', 'f') || CMP2 (val, 'n', 'o') || CMP1 (val, '0'))
    /* "off", "no" and "0" mean false. */
    bool_value = 0;
  else
    {
      fprintf (stderr,
	       _("%s: %s: Invalid boolean `%s'; use `on' or `off'.\n"),
	       exec_name, com, val);
      return 0;
    }

  *(int *)place = bool_value;
  return 1;
}

/* Set the non-negative integer value from VAL to PLACE.  With
   incorrect specification, the number remains unchanged.  */
static int
cmd_number (const char *com, const char *val, void *place)
{
  if (!simple_atoi (val, val + strlen (val), place)
