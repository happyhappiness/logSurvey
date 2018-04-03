
  if (flags == SP_FINISH)
    {
      if (expected)
	{
	  int dot = ndot;
	  char *tmpstr = (char *)alloca (2 * opt.dots_in_line + 1);
	  char *tmpp = tmpstr;
	  time_offset = elapsed_time () - last_timer;
	  for (; dot < opt.dots_in_line; dot++)
	    {
	      if (!(dot % opt.dot_spacing))
		*tmpp++ = ' ';
	      *tmpp++ = ' ';
	    }
	  *tmpp = '\0';
	  logputs (LOG_VERBOSE, tmpstr);
	  print_percentage (nrow * line_bytes + ndot * opt.dot_bytes + offs,
			    expected);
	  logprintf (LOG_VERBOSE, " @%s",
		     rate (ndot * opt.dot_bytes
			   + offs - (initial_skip % line_bytes),
			   time_offset, 1));
	}
      logputs (LOG_VERBOSE, "\n\n");
      return 0;
    }
