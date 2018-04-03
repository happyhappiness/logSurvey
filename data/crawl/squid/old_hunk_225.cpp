#endif

    if (getrlimit(RLIMIT_NOFILE, &rl) < 0) {
        debugs(50, DBG_CRITICAL, "getrlimit: RLIMIT_NOFILE: " << xstrerror());
    } else {
        rl.rlim_cur = Squid_MaxFD;
        if (setrlimit(RLIMIT_NOFILE, &rl) < 0) {
            snprintf(tmp_error_buf, ERROR_BUF_SZ, "setrlimit: RLIMIT_NOFILE: %s", xstrerror());
            fatal_dump(tmp_error_buf);
        }
    }
#endif /* HAVE_SETRLIMIT */

#if HAVE_SETRLIMIT && defined(RLIMIT_DATA) && !_SQUID_CYGWIN_
    if (getrlimit(RLIMIT_DATA, &rl) < 0) {
        debugs(50, DBG_CRITICAL, "getrlimit: RLIMIT_DATA: " << xstrerror());
    } else if (rl.rlim_max > rl.rlim_cur) {
        rl.rlim_cur = rl.rlim_max;  /* set it to the max */

        if (setrlimit(RLIMIT_DATA, &rl) < 0) {
            snprintf(tmp_error_buf, ERROR_BUF_SZ, "setrlimit: RLIMIT_DATA: %s", xstrerror());
            fatal_dump(tmp_error_buf);
        }
    }
