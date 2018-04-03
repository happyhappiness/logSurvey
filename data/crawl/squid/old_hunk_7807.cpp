
void setMaxFD()
{
#if defined(HAVE_SETRLIMIT)
    /* try to use as many file descriptors as possible */
    /* System V uses RLIMIT_NOFILE and BSD uses RLIMIT_OFILE */
    struct rlimit rl;
#if defined(RLIMIT_NOFILE)
    if (getrlimit(RLIMIT_NOFILE, &rl) < 0) {
	perror("getrlimit: RLIMIT_NOFILE");
    } else {
	rl.rlim_cur = rl.rlim_max;	/* set it to the max */
	if (setrlimit(RLIMIT_NOFILE, &rl) < 0) {
	    perror("setrlimit: RLIMIT_NOFILE");
	}
    }
#elif defined(RLIMIT_OFILE)
    if (getrlimit(RLIMIT_OFILE, &rl) < 0) {
	perror("getrlimit: RLIMIT_OFILE");
    } else {
	rl.rlim_cur = rl.rlim_max;	/* set it to the max */
	if (setrlimit(RLIMIT_OFILE, &rl) < 0) {
	    perror("setrlimit: RLIMIT_OFILE");
	}
    }
#endif
    debug(21, 1, "setMaxFD: Using %d file descriptors\n", rl.rlim_max);
#else /* HAVE_SETRLIMIT */
    debug(21, 1, "setMaxFD: Cannot increase: setrlimit() not supported on this system");
#endif
