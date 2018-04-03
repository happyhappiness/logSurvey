    {
    err:
      fprintf (stderr, _("%s: %s: Invalid time period `%s'\n"),
	       exec_name, com, val);
      return false;
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
      --end, mult = 86400.0;	/* days */
      break;
    case 'w':
      --end, mult = 604800.0;	/* weeks */
      break;
    default:
      /* Not a recognized suffix: assume it belongs to the number.
	 (If not, simple_atof will raise an error.)  */
      mult = 1;
    }

