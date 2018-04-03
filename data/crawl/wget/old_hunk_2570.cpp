      || *(int *) place < 0)
    {
      fprintf (stderr, _("%s: %s: Invalid number `%s'.\n"),
	       exec_name, com, val);
      return false;
    }
  return true;
