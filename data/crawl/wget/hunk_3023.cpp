 # endif
 #endif
 
-/* The type ptimer_system_time holds system time. */
-
 #ifdef PTIMER_POSIX
+/* Elapsed time measurement using POSIX timers: system time is held in
+   struct timespec, time is retrieved using clock_gettime, and
+   resolution using clock_getres.
+
+   This method is used on Unix systems that implement POSIX
+   timers.  */
+
 typedef struct timespec ptimer_system_time;
+
+#define IMPL_init posix_init
+#define IMPL_measure posix_measure
+#define IMPL_diff posix_diff
+#define IMPL_resolution posix_resolution
+
+/* clock_id to use for POSIX clocks.  This tries to use
+   CLOCK_MONOTONIC where available, CLOCK_REALTIME otherwise.  */
+static int posix_clock_id;
+
+/* Resolution of the clock, in milliseconds. */
+static double posix_millisec_resolution;
+
+/* Decide which clock_id to use.  */
+
+static void
+posix_init (void)
+{
+  /* List of clocks we want to support: some systems support monotonic
+     clocks, Solaris has "high resolution" clock (sometimes
+     unavailable except to superuser), and all should support the
+     real-time clock.  */
+#define NO_SYSCONF_CHECK -1
+  static const struct {
+    int id;
+    int sysconf_name;
+  } clocks[] = {
+#if defined(_POSIX_MONOTONIC_CLOCK) && _POSIX_MONOTONIC_CLOCK >= 0
+    { CLOCK_MONOTONIC, _SC_MONOTONIC_CLOCK },
+#endif
+#ifdef CLOCK_HIGHRES
+    { CLOCK_HIGHRES, NO_SYSCONF_CHECK },
 #endif
+    { CLOCK_REALTIME, NO_SYSCONF_CHECK },
+  };
+  int i;
+
+  /* Determine the clock we can use.  For a clock to be usable, it
+     must be confirmed with sysconf (where applicable) and with
+     clock_getres.  If no clock is found, CLOCK_REALTIME is used.  */
+
+  for (i = 0; i < countof (clocks); i++)
+    {
+      struct timespec r;
+      if (clocks[i].sysconf_name != NO_SYSCONF_CHECK)
+	if (sysconf (clocks[i].sysconf_name) < 0)
+	  continue;		/* sysconf claims this clock is unavailable */
+      if (clock_getres (clocks[i].id, &r) < 0)
+	continue;		/* clock_getres doesn't work for this clock */
+      posix_clock_id = clocks[i].id;
+      posix_millisec_resolution = r.tv_sec * 1000.0 + r.tv_nsec / 1000000.0;
+      /* Guard against broken clock_getres returning nonsensical
+	 values.  */
+      if (posix_millisec_resolution == 0)
+	posix_millisec_resolution = 1;
+      break;
+    }
+  if (i == countof (clocks))
+    {
+      /* If no clock was found, it means that clock_getres failed for
+	 the realtime clock.  */
+      logprintf (LOG_NOTQUIET, _("Cannot get REALTIME clock frequency: %s\n"),
+		 strerror (errno));
+      /* Use CLOCK_REALTIME, but invent a plausible resolution. */
+      posix_clock_id = CLOCK_REALTIME;
+      posix_millisec_resolution = 1;
+    }
+}
+
+static inline void
+posix_measure (ptimer_system_time *pst)
+{
+  clock_gettime (posix_clock_id, pst);
+}
+
+static inline double
+posix_diff (ptimer_system_time *pst1, ptimer_system_time *pst2)
+{
+  return ((pst1->tv_sec - pst2->tv_sec) * 1000.0
+	  + (pst1->tv_nsec - pst2->tv_nsec) / 1000000.0);
+}
+
+static inline double
+posix_resolution (void)
+{
+  return posix_millisec_resolution;
+}
+#endif	/* PTIMER_POSIX */
 
 #ifdef PTIMER_GETTIMEOFDAY
+/* Elapsed time measurement using gettimeofday: system time is held in
+   struct timeval, retrieved using gettimeofday, and resolution is
+   unknown.
+
+   This method is used Unix systems without POSIX timers.  */
+
 typedef struct timeval ptimer_system_time;
-#endif
+
+#define IMPL_measure gettimeofday_measure
+#define IMPL_diff gettimeofday_diff
+#define IMPL_resolution gettimeofday_resolution
+
+static inline void
+gettimeofday_measure (ptimer_system_time *pst)
+{
+  gettimeofday (pst, NULL);
+}
+
+static inline double
+gettimeofday_diff (ptimer_system_time *pst1, ptimer_system_time *pst2)
+{
+  return ((pst1->tv_sec - pst2->tv_sec) * 1000.0
+	  + (pst1->tv_usec - pst2->tv_usec) / 1000.0);
+}
+
+static inline double
+gettimeofday_resolution (void)
+{
+  /* Granularity of gettimeofday varies wildly between architectures.
+     However, it appears that on modern machines it tends to be better
+     than 1ms.  Assume 100 usecs.  */
+  return 0.1;
+}
+#endif	/* PTIMER_GETTIMEOFDAY */
 
 #ifdef PTIMER_TIME
+/* Elapsed time measurement using the time(2) call: system time is
+   held in time_t, retrieved using time, and resolution is 1 second.
+
+   This method is a catch-all for non-Windows systems without
+   gettimeofday -- e.g. DOS or really old or non-standard Unix
+   systems.  */
+
 typedef time_t ptimer_system_time;
-#endif
+
+#define IMPL_measure time_measure
+#define IMPL_diff time_diff
+#define IMPL_resolution time_resolution
+
+static inline void
+time_measure (ptimer_system_time *pst)
+{
+  time (pst);
+}
+
+static inline double
+time_diff (ptimer_system_time *pst1, ptimer_system_time *pst2)
+{
+  return 1000.0 * (*pst1 - *pst2);
+}
+
+static inline double
+time_resolution (void)
+{
+  return 1;
+}
+#endif	/* PTIMER_TIME */
 
 #ifdef PTIMER_WINDOWS
+/* Elapsed time measurement on Windows: where high-resolution timers
+   are available, time is stored in a LARGE_INTEGER and retrieved
+   using QueryPerformanceCounter.  Otherwise, it is stored in a DWORD
+   and retrieved using GetTickCount.
+
+   This method is used on Windows.  */
+
 typedef union {
   DWORD lores;          /* In case GetTickCount is used */
   LARGE_INTEGER hires;  /* In case high-resolution timer is used */
 } ptimer_system_time;
-#endif
 
-struct ptimer {
-  /* Whether the start time has been set. */
-  int initialized;
-
-  /* The starting point in time which, subtracted from the current
-     time, yields elapsed time. */
-  ptimer_system_time start;
+#define IMPL_init windows_init
+#define IMPL_measure windows_measure
+#define IMPL_diff windows_diff
+#define IMPL_resolution windows_resolution
 
-  /* The most recent elapsed time, calculated by ptimer_measure().
-     Measured in milliseconds.  */
-  double elapsed_last;
-
-  /* Approximately, the time elapsed between the true start of the
-     measurement and the time represented by START.  */
-  double elapsed_pre_start;
-};
-
-#ifdef PTIMER_WINDOWS
 /* Whether high-resolution timers are used.  Set by ptimer_initialize_once
-   the first time ptimer_allocate is called. */
+   the first time ptimer_new is called. */
 static int windows_hires_timers;
 
 /* Frequency of high-resolution timers -- number of updates per
-   millisecond.  Calculated the first time ptimer_allocate is called
+   millisecond.  Calculated the first time ptimer_new is called
    provided that high-resolution timers are available. */
 static double windows_hires_msfreq;
 
-/* The first time a timer is created, determine whether to use
-   high-resolution timers. */
-
 static void
-ptimer_init (void)
+windows_init (void)
 {
   LARGE_INTEGER freq;
   freq.QuadPart = 0;
