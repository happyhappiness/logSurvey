static unsigned int get_max_fd_limit(void)
{
#ifdef RLIMIT_NOFILE
	struct rlimit lim;

	if (getrlimit(RLIMIT_NOFILE, &lim))
		die_errno("cannot get RLIMIT_NOFILE");

	return lim.rlim_cur;
#elif defined(_SC_OPEN_MAX)
	return sysconf(_SC_OPEN_MAX);
#elif defined(OPEN_MAX)
	return OPEN_MAX;
#else
	return 1; /* see the caller ;-) */