    }

#if HAVE_SETRESUID
    if (setresuid(Config2.effectiveUserID, Config2.effectiveUserID, 0) < 0) {
        const auto xerrno = errno;
        fatalf("FATAL: setresuid: %s", xstrerr(xerrno));
    }

#elif HAVE_SETEUID
    if (seteuid(Config2.effectiveUserID) < 0) {
        const auto xerrno = errno;
        fatalf("FATAL: seteuid: %s", xstrerr(xerrno));
    }

#else
    if (setuid(Config2.effectiveUserID) < 0) {
        const auto xerrno = errno;
        fatalf("FATAL: setuid: %s", xstrerr(xerrno));
    }

#endif

