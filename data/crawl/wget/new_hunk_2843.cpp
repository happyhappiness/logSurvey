      fprintf (stderr,
	       _("%s: %s: Invalid restriction `%s', use `unix' or `windows'.\n"),
	       exec_name, com, val);
      return false;
    }

#undef VAL_IS
