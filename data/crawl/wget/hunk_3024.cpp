       windows_hires_msfreq = (double) freq.QuadPart / 1000.0;
     }
 }
-#define PTIMER_INIT_DEFINED
-#endif /* PTIMER_WINDOWS */
-
-#ifdef PTIMER_POSIX
-
-/* clock_id to use for POSIX clocks.  This tries to use
-   CLOCK_MONOTONIC where available, CLOCK_REALTIME otherwise.  */
-static int posix_clock_id;
 
-/* Resolution of the clock, in milliseconds. */
-static double posix_resolution;
-
-/* Check whether the monotonic clock is available, and retrieve POSIX
-   timer resolution.  */
+static inline void
+windows_measure (ptimer_system_time *pst)
+{
+  if (windows_hires_timers)
+    QueryPerformanceCounter (&pst->hires);
+  else
+    /* Where hires counters are not available, use GetTickCount rather
+       GetSystemTime, because it is unaffected by clock skew and
+       simpler to use.  Note that overflows don't affect us because we
+       never use absolute values of the ticker, only the
+       differences.  */
+    pst->lores = GetTickCount ();
+}
 
-static void
-ptimer_init (void)
+static inline double
+windows_diff (ptimer_system_time *pst1, ptimer_system_time *pst2)
 {
-  struct timespec res;
+  if (windows_hires_timers)
+    return (pst1->hires.QuadPart - pst2->hires.QuadPart) / windows_hires_msfreq;
+  else
+    return pst1->lores - pst2->lores;
+}
 
-#if _POSIX_MONOTONIC_CLOCK >= 0	           /* -1 means not supported */
-  if (sysconf (_SC_MONOTONIC_CLOCK) > 0)
-    posix_clock_id = CLOCK_MONOTONIC;
+static double
+windows_resolution (void)
+{
+  if (windows_hires_timers)
+    return 1.0 / windows_hires_msfreq;
   else
-#endif
-    posix_clock_id = CLOCK_REALTIME;
+    return 10;			/* according to MSDN */
+}
+#endif	/* PTIMER_WINDOWS */
+
+/* The code below this point is independent of timer implementation. */
 
-  if (clock_getres (posix_clock_id, &res) < 0)
-    {
-      logprintf (LOG_NOTQUIET, _("Cannot read clock resolution: %s\n"),
-		 strerror (errno));
-      /* Assume 1 ms resolution */
-      res.tv_sec = 0;
-      res.tv_nsec = 1000000;
-    }
+struct ptimer {
+  /* Whether the start time has been set. */
+  int initialized;
 
-  posix_resolution = res.tv_sec * 1000.0 + res.tv_nsec / 1000000.0;
-  /* Guard against clock_getres reporting 0 resolution; after all, it
-     can be used for division.  */
-  if (posix_resolution == 0)
-    posix_resolution = 1;
-}
-#define PTIMER_INIT_DEFINED
-#endif
+  /* The starting point in time which, subtracted from the current
+     time, yields elapsed time. */
+  ptimer_system_time start;
 
-/* Allocate a timer.  Calling ptimer_read on the timer will return
-   zero.  It is not legal to call ptimer_measure with a freshly
-   allocated timer -- use ptimer_reset first.  */
+  /* The most recent elapsed time, calculated by ptimer_measure().
+     Measured in milliseconds.  */
+  double elapsed_last;
+
+  /* Approximately, the time elapsed between the true start of the
+     measurement and the time represented by START.  This is used for
+     adjustment when clock skew is detected.  */
+  double elapsed_pre_start;
+};
+
+/* Allocate a new timer and reset it.  Return the new timer. */
 
 struct ptimer *
-ptimer_allocate (void)
+ptimer_new (void)
 {
-  struct ptimer *wt;
-
-#ifdef PTIMER_INIT_DEFINED
+  struct ptimer *wt = xnew0 (struct ptimer);
+#ifdef IMPL_init
   static int init_done;
   if (!init_done)
     {
       init_done = 1;
-      ptimer_init ();
+      IMPL_init ();
     }
 #endif
-
-  wt = xnew0 (struct ptimer);
-  return wt;
-}
-
-/* Allocate a new timer and reset it.  Return the new timer. */
-
-struct ptimer *
-ptimer_new (void)
-{
-  struct ptimer *wt = ptimer_allocate ();
   ptimer_reset (wt);
   return wt;
 }
