    d->file->command_state = state;
}

/* Get and print file timestamps.  */

FILE_TIMESTAMP
file_timestamp_now ()
{
  /* Don't bother with high-resolution clocks if file timestamps have
     only one-second resolution.  The code below should work, but it's
     not worth the hassle of debugging it on hosts where it fails.  */
  if (1 < FILE_TIMESTAMPS_PER_S)
    {
#if HAVE_CLOCK_GETTIME && defined CLOCK_REALTIME
      {
	struct timespec timespec;
	if (clock_gettime (CLOCK_REALTIME, &timespec) == 0)
	  return FILE_TIMESTAMP_FROM_S_AND_NS (timespec.tv_sec,
					       timespec.tv_nsec);
      }
#endif
#if HAVE_GETTIMEOFDAY
      {
	struct timeval timeval;
	if (gettimeofday (&timeval, 0) == 0)
	  return FILE_TIMESTAMP_FROM_S_AND_NS (timeval.tv_sec,
					       timeval.tv_usec * 1000);
      }
#endif
    }

  return FILE_TIMESTAMP_FROM_S_AND_NS (time ((time_t *) 0), 0);
}

void
