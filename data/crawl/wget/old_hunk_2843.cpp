      fprintf (stderr,
	       _("%s: %s: Invalid restriction `%s', use `unix' or `windows'.\n"),
	       exec_name, com, val);
      return 0;
    }

#undef VAL_IS