# endif
#endif

/* The type ptimer_system_time holds system time. */

#ifdef PTIMER_POSIX
typedef struct timespec ptimer_system_time;
#endif

#ifdef PTIMER_GETTIMEOFDAY
typedef struct timeval ptimer_system_time;
#endif

#ifdef PTIMER_TIME
typedef time_t ptimer_system_time;
#endif

#ifdef PTIMER_WINDOWS
typedef union {
  DWORD lores;          /* In case GetTickCount is used */
  LARGE_INTEGER hires;  /* In case high-resolution timer is used */
} ptimer_system_time;
#endif

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
     measurement and the time represented by START.  */
  double elapsed_pre_start;
};

#ifdef PTIMER_WINDOWS
/* Whether high-resolution timers are used.  Set by ptimer_initialize_once
   the first time ptimer_allocate is called. */
static int windows_hires_timers;

/* Frequency of high-resolution timers -- number of updates per
   millisecond.  Calculated the first time ptimer_allocate is called
   provided that high-resolution timers are available. */
static double windows_hires_msfreq;

/* The first time a timer is created, determine whether to use
   high-resolution timers. */

static void
ptimer_init (void)
{
  LARGE_INTEGER freq;
  freq.QuadPart = 0;
