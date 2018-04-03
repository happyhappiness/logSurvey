    if (setuid(Config2.effectiveUserID) < 0)
        debug(50, 0) ("ALERT: setuid: %s\n", xstrerror());

#endif
#if HAVE_PRCTL && defined(PR_SET_DUMPABLE)
    /* Set Linux DUMPABLE flag */
