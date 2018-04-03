    {
      struct timespec r;
      if (clocks[i].sysconf_name != NO_SYSCONF_CHECK)
        if (sysconf (clocks[i].sysconf_name) < 0)
          continue;             /* sysconf claims this clock is unavailable */
      if (clock_getres (clocks[i].id, &r) < 0)
        continue;               /* clock_getres doesn't work for this clock */
      posix_clock_id = clocks[i].id;
      posix_clock_resolution = (double) r.tv_sec + r.tv_nsec / 1e9;
      /* Guard against nonsense returned by a broken clock_getres.  */
      if (posix_clock_resolution == 0)
        posix_clock_resolution = 1e-3;
      break;
    }
  if (i == countof (clocks))
    {
      /* If no clock was found, it means that clock_getres failed for
         the realtime clock.  */
      logprintf (LOG_NOTQUIET, _("Cannot get REALTIME clock frequency: %s\n"),
                 strerror (errno));
      /* Use CLOCK_REALTIME, but invent a plausible resolution. */
      posix_clock_id = CLOCK_REALTIME;
      posix_clock_resolution = 1e-3;
