    getrusage(RUSAGE_SELF, &rusage);
    fprintf(lf, "CPU Usage: user %d sys %d\n",
	(int) rusage.ru_utime.tv_sec, (int) rusage.ru_stime.tv_sec);
#ifdef _SQUID_SGI_
    fprintf(lf, "Memory Usage: rss %ld KB\n", rusage.ru_maxrss);
#else
    fprintf(lf, "Memory Usage: rss %ld KB\n",
	(rusage.ru_maxrss * getpagesize()) >> 10);
#endif /* _SQUID_SGI_ */
    fprintf(lf, "Page faults with physical i/o: %ld\n",
	rusage.ru_majflt);
#endif /* HAVE_GETRUSAGE */
    dumpMallocStats(lf);
    if (f)
	f();