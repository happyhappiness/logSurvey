    d->file->command_state = state;
}

/* Convert an external file timestamp to internal form.  */

FILE_TIMESTAMP
file_timestamp_cons (fname, s, ns)
     char const *fname;
     time_t s;
     int ns;
{
  int offset = ORDINARY_MTIME_MIN + (FILE_TIMESTAMP_HI_RES ? ns : 0);
  FILE_TIMESTAMP product = (FILE_TIMESTAMP) s << FILE_TIMESTAMP_LO_BITS;
  FILE_TIMESTAMP ts = product + offset;

  if (! (s <= FILE_TIMESTAMP_S (ORDINARY_MTIME_MAX)
	 && product <= ts && ts <= ORDINARY_MTIME_MAX))
    {
      char buf[FILE_TIMESTAMP_PRINT_LEN_BOUND + 1];
      ts = s <= OLD_MTIME ? ORDINARY_MTIME_MIN : ORDINARY_MTIME_MAX;
      file_timestamp_sprintf (buf, ts);
      error (NILF, _("%s: Timestamp out of range; substituting %s"),
	     fname ? fname : _("Current time"), buf);
    }
    
  return ts;
}

/* Get and print file timestamps.  */

FILE_TIMESTAMP
file_timestamp_now ()
{
  time_t s;
  int ns;

  /* Don't bother with high-resolution clocks if file timestamps have
     only one-second resolution.  The code below should work, but it's
     not worth the hassle of debugging it on hosts where it fails.  */
  if (FILE_TIMESTAMP_HI_RES)
    {
#if HAVE_CLOCK_GETTIME && defined CLOCK_REALTIME
      {
	struct timespec timespec;
	if (clock_gettime (CLOCK_REALTIME, &timespec) == 0)
	  {
	    s = timespec.tv_sec;
	    ns = timespec.tv_nsec;
	    goto got_time;
	  }
      }
#endif
#if HAVE_GETTIMEOFDAY
      {
	struct timeval timeval;
	if (gettimeofday (&timeval, 0) == 0)
	  {
	    s = timeval.tv_sec;
	    ns = timeval.tv_usec * 1000;
	    goto got_time;
	  }
      }
#endif
    }

  s = time ((time_t *) 0);
  ns = 0;

 got_time:
  return file_timestamp_cons (0, s, ns);
}

void
