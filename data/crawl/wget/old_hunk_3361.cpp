  return 1;
}

/* Set the non-negative integer value from VAL to CLOSURE.  With
   incorrect specification, the number remains unchanged.  */
static int
cmd_number (const char *com, const char *val, void *closure)
{
  int num = myatoi (val);

  if (num == -1)
    {
      fprintf (stderr, _("%s: %s: Invalid specification `%s'.\n"),
	       exec_name, com, val);
      return 0;
    }
  *(int *)closure = num;
  return 1;
}

