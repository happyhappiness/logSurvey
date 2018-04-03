    return pid;
}


void
setMaxFD(void)
{
#if HAVE_SETRLIMIT
    /* try to use as many file descriptors as possible */
    /* System V uses RLIMIT_NOFILE and BSD uses RLIMIT_OFILE */

    struct rlimit rl;
#if defined(RLIMIT_NOFILE)

    if (getrlimit(RLIMIT_NOFILE, &rl) < 0) {
        debugs(50, 0, "setrlimit: RLIMIT_NOFILE: " << xstrerror());
    } else {
        rl.rlim_cur = Squid_MaxFD;

        if (rl.rlim_cur > rl.rlim_max)
            Squid_MaxFD = rl.rlim_cur = rl.rlim_max;

        if (setrlimit(RLIMIT_NOFILE, &rl) < 0) {
            snprintf(tmp_error_buf, ERROR_BUF_SZ,
                     "setrlimit: RLIMIT_NOFILE: %s", xstrerror());
            fatal_dump(tmp_error_buf);
        }
    }

#elif defined(RLIMIT_OFILE)
    if (getrlimit(RLIMIT_OFILE, &rl) < 0) {
        debugs(50, 0, "setrlimit: RLIMIT_NOFILE: " << xstrerror());
    } else {
        rl.rlim_cur = Squid_MaxFD;

        if (rl.rlim_cur > rl.rlim_max)
            Squid_MaxFD = rl.rlim_cur = rl.rlim_max;

        if (setrlimit(RLIMIT_OFILE, &rl) < 0) {
            snprintf(tmp_error_buf, ERROR_BUF_SZ,
                     "setrlimit: RLIMIT_OFILE: %s", xstrerror());
            fatal_dump(tmp_error_buf);
        }
    }

#endif
#else /* HAVE_SETRLIMIT */
    debugs(21, 1, "setMaxFD: Cannot increase: setrlimit() not supported on this system");

#endif /* HAVE_SETRLIMIT */

#if HAVE_SETRLIMIT && defined(RLIMIT_DATA)

    if (getrlimit(RLIMIT_DATA, &rl) < 0) {
        debugs(50, 0, "getrlimit: RLIMIT_DATA: " << xstrerror());
    } else if (rl.rlim_max > rl.rlim_cur) {
        rl.rlim_cur = rl.rlim_max;	/* set it to the max */

        if (setrlimit(RLIMIT_DATA, &rl) < 0) {
            snprintf(tmp_error_buf, ERROR_BUF_SZ,
                     "setrlimit: RLIMIT_DATA: %s", xstrerror());
            fatal_dump(tmp_error_buf);
        }
    }

#endif /* RLIMIT_DATA */
#if HAVE_SETRLIMIT && defined(RLIMIT_VMEM)
    if (getrlimit(RLIMIT_VMEM, &rl) < 0) {
        debugs(50, 0, "getrlimit: RLIMIT_VMEM: " << xstrerror());
    } else if (rl.rlim_max > rl.rlim_cur) {
        rl.rlim_cur = rl.rlim_max;	/* set it to the max */

        if (setrlimit(RLIMIT_VMEM, &rl) < 0) {
            snprintf(tmp_error_buf, ERROR_BUF_SZ,
                     "setrlimit: RLIMIT_VMEM: %s", xstrerror());
            fatal_dump(tmp_error_buf);
        }
    }

#endif /* RLIMIT_VMEM */
}
