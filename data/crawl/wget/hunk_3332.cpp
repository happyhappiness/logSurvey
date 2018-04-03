   logputs (LOG_VERBOSE, (n1 == n2) ? _("Giving up.\n\n") : _("Retrying.\n\n"));
 }
 
-/* Increment opt.downloaded by BY_HOW_MUCH.  If an overflow occurs,
-   set opt.downloaded_overflow to 1. */
-void
-downloaded_increase (unsigned long by_how_much)
-{
-  VERY_LONG_TYPE old;
-  if (opt.downloaded_overflow)
-    return;
-  old = opt.downloaded;
-  opt.downloaded += by_how_much;
-  if (opt.downloaded < old)	/* carry flag, where are you when I
-                                   need you? */
-    {
-      /* Overflow. */
-      opt.downloaded_overflow = 1;
-      opt.downloaded = ~((VERY_LONG_TYPE)0);
-    }
-}
-
-/* Return non-zero if the downloaded amount of bytes exceeds the
-   desired quota.  If quota is not set or if the amount overflowed, 0
-   is returned. */
-int
-downloaded_exceeds_quota (void)
-{
-  if (!opt.quota)
-    return 0;
-  if (opt.downloaded_overflow)
-    /* We don't really know.  (Wildly) assume not. */
-    return 0;
-
-  return opt.downloaded > opt.quota;
-}
-
 /* If opt.wait or opt.waitretry are specified, and if certain
    conditions are met, sleep the appropriate number of seconds.  See
    the documentation of --wait and --waitretry for more information.
