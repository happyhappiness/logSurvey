    {
      int val;
      struct cmdline_option *opt;
      if (ret == '?')
	{
	  print_usage ();
	  printf ("\n");
	  printf (_("Try `%s --help' for more options.\n"), exec_name);
	  exit (2);
	}

      /* If LONGINDEX is unchanged, it means RET is referring a short
	 option.  Look it up in the mapping table.  */
      if (longindex == -1)
	longindex = optmap[ret - 32];
      val = long_options[longindex].val;

      /* Use the retrieved value to locate the option in the
