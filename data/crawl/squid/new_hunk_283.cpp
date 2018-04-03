#endif

    if (getrlimit(RLIMIT_NOFILE, &rl) < 0) {
        int xerrno = errno;
        debugs(50, DBG_CRITICAL, "getrlimit: RLIMIT_NOFILE: " << xstrerr(xerrno));
    } else {
        rl.rlim_cur = Squid_MaxFD;
        if (setrlimit(RLIMIT_NOFILE, &rl) < 0) {
            int xerrno = errno;
            snprintf(tmp_error_buf, ERROR_BUF_SZ, "setrlimit: RLIMIT_NOFILE: %s", xstrerr(xerrno));
            fatal_dump(tmp_error_buf);
        }
    }
#endif /* HAVE_SETRLIMIT */

#if HAVE_SETRLIMIT && defined(RLIMIT_DATA) && !_SQUID_CYGWIN_
    if (getrlimit(RLIMIT_DATA, &rl) < 0) {
        int xerrno = errno;
        debugs(50, DBG_CRITICAL, "getrlimit: RLIMIT_DATA: " << xstrerr(xerrno));
    } else if (rl.rlim_max > rl.rlim_cur) {
        rl.rlim_cur = rl.rlim_max;  /* set it to the max */

        if (setrlimit(RLIMIT_DATA, &rl) < 0) {
            int xerrno = errno;
            snprintf(tmp_error_buf, ERROR_BUF_SZ, "setrlimit: RLIMIT_DATA: %s", xstrerr(xerrno));
            fatal_dump(tmp_error_buf);
        }
    }
