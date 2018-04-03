  if (res < -1)
    res = -1;
  if (opt.verbose)
    show_progress (0, expected, SP_FINISH);
  return res;
}

static void
print_percentage (long bytes, long expected)
{
  int percentage = (int)(100.0 * bytes / expected);
  logprintf (LOG_VERBOSE, "%3d%%", percentage);
}

/* Show the dotted progress report of file loading.  Called with
   length and a flag to tell it whether to reset or not.  It keeps the
   offset information in static local variables.

   Return value: 1 or 0, designating whether any dots have been drawn.

   If the init argument is set, the routine will initialize.

   If the res is non-zero, res/line_bytes lines are skipped
   (meaning the appropriate number ok kilobytes), and the number of
   "dots" fitting on the first line are drawn as ','.  */
static int
show_progress (long res, long expected, enum spflags flags)
{
  static struct wget_timer *timer;
  static long line_bytes;
  static long offs, initial_skip;
  static int ndot, nrow;
  static long last_timer_value, time_offset;
  int any_output = 0;

  if (flags == SP_FINISH)
    {
      int dot = ndot;
      char *tmpstr = (char *)alloca (2 * opt.dots_in_line + 1);
      char *tmpp = tmpstr;
      time_offset = wtimer_elapsed (timer) - last_timer_value;
      for (; dot < opt.dots_in_line; dot++)
	{
	  if (!(dot % opt.dot_spacing))
	    *tmpp++ = ' ';
	  *tmpp++ = ' ';
	}
      *tmpp = '\0';
      logputs (LOG_VERBOSE, tmpstr);
      if (expected)
	print_percentage (nrow * line_bytes + ndot * opt.dot_bytes + offs,
			  expected);
      logprintf (LOG_VERBOSE, " @%s",
		 rate (ndot * opt.dot_bytes
		       + offs - (initial_skip % line_bytes),
		       time_offset, 1));
      logputs (LOG_VERBOSE, "\n\n");
      return 0;
    }

  /* Temporarily disable flushing.  */
  log_set_flush (0);

  /* init set means initialization.  If res is set, it also means that
     the retrieval is *not* done from the beginning.  The part that
     was already retrieved is not shown again.  */
  if (flags == SP_INIT)
    {
      /* Generic initialization of static variables.  */
      offs = 0L;
      ndot = nrow = 0;
      line_bytes = (long)opt.dots_in_line * opt.dot_bytes;
      if (!timer)
	timer = wtimer_allocate ();
      wtimer_reset (timer);
      last_timer_value = 0;
      time_offset = 0;
      initial_skip = res;
      if (res)
	{
	  if (res >= line_bytes)
	    {
	      nrow = res / line_bytes;
	      res %= line_bytes;
	      logprintf (LOG_VERBOSE,
			 _("\n          [ skipping %dK ]"),
			 (int) ((nrow * line_bytes) / 1024));
	      ndot = 0;
	    }
	}
      logprintf (LOG_VERBOSE, "\n%5ldK", nrow * line_bytes / 1024);
    }
  /* Offset gets incremented by current value.  */
  offs += res;
  /* While offset is >= opt.dot_bytes, print dots, taking care to
     precede every 50th dot with a status message.  */
  for (; offs >= opt.dot_bytes; offs -= opt.dot_bytes)
    {
      if (!(ndot % opt.dot_spacing))
	logputs (LOG_VERBOSE, " ");
      any_output = 1;
      logputs (LOG_VERBOSE, flags == SP_INIT ? "," : ".");
      ++ndot;
      if (ndot == opt.dots_in_line)
	{
	  time_offset = wtimer_elapsed (timer) - last_timer_value;
	  last_timer_value += time_offset;

	  ndot = 0;
	  ++nrow;
	  if (expected)
	    print_percentage (nrow * line_bytes, expected);
	  logprintf (LOG_VERBOSE, " @%s",
		     rate (line_bytes - (initial_skip % line_bytes),
			   time_offset, 1));
	  initial_skip = 0;
	  logprintf (LOG_VERBOSE, "\n%5ldK", nrow * line_bytes / 1024);
	}
    }

  /* Reenable flushing.  */
  log_set_flush (1);

  return any_output;
}

/* Print out the appropriate download rate.  Appropriate means that if
   rate is > 1024 bytes per second, kilobytes are used, and if rate >
   1024 * 1024 bps, megabytes are used.

   If PAD is non-zero, strings will be padded to the width of 7
   characters (xxxx.xx).  */
