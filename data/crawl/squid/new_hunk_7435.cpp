    getrusage(RUSAGE_SELF, &rusage);
    fprintf(lf, "CPU Usage: user %d sys %d\n",
	(int) rusage.ru_utime.tv_sec, (int) rusage.ru_stime.tv_sec);
#if defined(_SQUID_SGI_) || defined(_SQUID_OSF_)
    fprintf(lf, "Memory Usage: rss %ld KB\n", rusage.ru_maxrss);
#else /* _SQUID_SGI_ */
    fprintf(lf, "Memory Usage: rss %ld KB\n",
	(rusage.ru_maxrss * getpagesize()) >> 10);
#endif /* _SQUID_SGI_ */