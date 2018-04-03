  return 1;
}

static int simple_atoi PARAMS ((const char *, const char *, int *));

/* Set the non-negative integer value from VAL to CLOSURE.  With
   incorrect specification, the number remains unchanged.  */
static int
cmd_number (const char *com, const char *val, void *closure)
{
  if (!simple_atoi (val, val + strlen (val), closure))
    {
      fprintf (stderr, _("%s: %s: Invalid number `%s'.\n"),
	       exec_name, com, val);
      return 0;
    }
  return 1;
}

