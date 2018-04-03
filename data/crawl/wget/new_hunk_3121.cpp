    {
      int val;
      struct cmdline_option *opt;

      /* If LONGINDEX is unchanged, it means RET is referring a short
	 option.  */
      if (longindex == -1)
	{
	  if (ret == '?')
	    {
	      print_usage ();
	      printf ("\n");
	      printf (_("Try `%s --help' for more options.\n"), exec_name);
	      exit (2);
	    }
	  /* Find the short option character in the mapping.  */
	  longindex = optmap[ret - 32];
	}
      val = long_options[longindex].val;

      /* Use the retrieved value to locate the option in the
