        debugs(50, 0, "ALERT: setuid: " << xstrerror());

#endif

    restoreCapabilities(1);

#if HAVE_PRCTL && defined(PR_SET_DUMPABLE)
    /* Set Linux DUMPABLE flag */
    if (Config.coredump_dir && prctl(PR_SET_DUMPABLE, 1) != 0)
