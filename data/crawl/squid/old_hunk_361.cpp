    }

#if HAVE_SETRESUID

    if (setresuid(Config2.effectiveUserID, Config2.effectiveUserID, 0) < 0)
        debugs(50, DBG_CRITICAL, "ALERT: setresuid: " << xstrerror());

#elif HAVE_SETEUID

    if (seteuid(Config2.effectiveUserID) < 0)
        debugs(50, DBG_CRITICAL, "ALERT: seteuid: " << xstrerror());

#else

    if (setuid(Config2.effectiveUserID) < 0)
        debugs(50, DBG_CRITICAL, "ALERT: setuid: " << xstrerror());

#endif

