      windows_hires_msfreq = (double) freq.QuadPart / 1000.0;
    }
}
#define PTIMER_INIT_DEFINED
#endif /* PTIMER_WINDOWS */

#ifdef PTIMER_POSIX

/* clock_id to use for POSIX clocks.  This tries to use
   CLOCK_MONOTONIC where available, CLOCK_REALTIME otherwise.  */
static int posix_clock_id;

/* Resolution of the clock, in milliseconds. */
static double posix_resolution;

/* Check whether the monotonic clock is available, and retrieve POSIX
   timer resolution.  */

static void
ptimer_init (void)
{
  struct timespec res;

#if _POSIX_MONOTONIC_CLOCK >= 0	           /* -1 means not supported */
  if (sysconf (_SC_MONOTONIC_CLOCK) > 0)
    posix_clock_id = CLOCK_MONOTONIC;
  else
#endif
    posix_clock_id = CLOCK_REALTIME;

  if (clock_getres (posix_clock_id, &res) < 0)
    {
      logprintf (LOG_NOTQUIET, _("Cannot read clock resolution: %s\n"),
		 strerror (errno));
      /* Assume 1 ms resolution */
      res.tv_sec = 0;
      res.tv_nsec = 1000000;
    }

  posix_resolution = res.tv_sec * 1000.0 + res.tv_nsec / 1000000.0;
  /* Guard against clock_getres reporting 0 resolution; after all, it
     can be used for division.  */
  if (posix_resolution == 0)
    posix_resolution = 1;
}
#define PTIMER_INIT_DEFINED
#endif

/* Allocate a timer.  Calling ptimer_read on the timer will return
   zero.  It is not legal to call ptimer_measure with a freshly
   allocated timer -- use ptimer_reset first.  */

struct ptimer *
ptimer_allocate (void)
{
  struct ptimer *wt;

#ifdef PTIMER_INIT_DEFINED
  static int init_done;
  if (!init_done)
    {
      init_done = 1;
      ptimer_init ();
    }
#endif

  wt = xnew0 (struct ptimer);
  return wt;
}

/* Allocate a new timer and reset it.  Return the new timer. */

struct ptimer *
ptimer_new (void)
{
  struct ptimer *wt = ptimer_allocate ();
  ptimer_reset (wt);
  return wt;
}
