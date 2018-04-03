      windows_hires_msfreq = (double) freq.QuadPart / 1000.0;
    }
}

static inline void
windows_measure (ptimer_system_time *pst)
{
  if (windows_hires_timers)
    QueryPerformanceCounter (&pst->hires);
  else
    /* Where hires counters are not available, use GetTickCount rather
       GetSystemTime, because it is unaffected by clock skew and
       simpler to use.  Note that overflows don't affect us because we
       never use absolute values of the ticker, only the
       differences.  */
    pst->lores = GetTickCount ();
}

static inline double
windows_diff (ptimer_system_time *pst1, ptimer_system_time *pst2)
{
  if (windows_hires_timers)
    return (pst1->hires.QuadPart - pst2->hires.QuadPart) / windows_hires_msfreq;
  else
    return pst1->lores - pst2->lores;
}

static double
windows_resolution (void)
{
  if (windows_hires_timers)
    return 1.0 / windows_hires_msfreq;
  else
    return 10;			/* according to MSDN */
}
#endif	/* PTIMER_WINDOWS */

/* The code below this point is independent of timer implementation. */

struct ptimer {
  /* Whether the start time has been set. */
  int initialized;

  /* The starting point in time which, subtracted from the current
     time, yields elapsed time. */
  ptimer_system_time start;

  /* The most recent elapsed time, calculated by ptimer_measure().
     Measured in milliseconds.  */
  double elapsed_last;

  /* Approximately, the time elapsed between the true start of the
     measurement and the time represented by START.  This is used for
     adjustment when clock skew is detected.  */
  double elapsed_pre_start;
};

/* Allocate a new timer and reset it.  Return the new timer. */

struct ptimer *
ptimer_new (void)
{
  struct ptimer *wt = xnew0 (struct ptimer);
#ifdef IMPL_init
  static int init_done;
  if (!init_done)
    {
      init_done = 1;
      IMPL_init ();
    }
#endif
  ptimer_reset (wt);
  return wt;
}
