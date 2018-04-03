#endif
#else /* HAVE_SETRLIMIT */
    debug(21, 1, "setMaxFD: Cannot increase: setrlimit() not supported on this system");
#endif /* HAVE_SETRLIMIT */

#if HAVE_SETRLIMIT && defined(RLIMIT_DATA)
    if (getrlimit(RLIMIT_DATA, &rl) < 0) {
	debug(21, 0, "getrlimit: RLIMIT_DATA: %s", xstrerror());
    } else {
	rl.rlim_cur = rl.rlim_max;	/* set it to the max */
	if (setrlimit(RLIMIT_DATA, &rl) < 0) {
	    sprintf(tmp_error_buf, "setrlimit: RLIMIT_DATA: %s", xstrerror());
	    fatal_dump(tmp_error_buf);
	}
    }
#endif /* RLIMIT_DATA */
}

time_t getCurrentTime()
{
#if defined(_SQUID_MOTOROLA_)
    gettimeofday(&current_time);
#else
    gettimeofday(&current_time, NULL);
#endif
    return squid_curtime = current_time.tv_sec;
}

int tvSubMsec(t1, t2)
