    getrusage(RUSAGE_SELF, &rusage);
    fprintf(lf, "CPU Usage: user %d sys %d\n",
	(int) rusage.ru_utime.tv_sec, (int) rusage.ru_stime.tv_sec);
    fprintf(lf, "Memory Usage: rss %ld KB\n",
	rusage.ru_maxrss * getpagesize() >> 10);
    fprintf(lf, "Page faults with physical i/o: %ld\n",
	rusage.ru_majflt);
#endif
    dumpMallocStats(lf);
    if (f)
	f();