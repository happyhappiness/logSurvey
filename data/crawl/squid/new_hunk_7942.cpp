	puts(dead_msg());
}

int PrintRusage(f, lf)
     void (*f) ();
     FILE *lf;
{
#if HAVE_RUSAGE && defined(RUSAGE_SELF)
    struct rusage rusage;
    getrusage(RUSAGE_SELF, &rusage);
    fprintf(lf, "CPU Usage: user %d sys %d\nMemory Usage: rss %d KB\n",
	rusage.ru_utime.tv_sec, rusage.ru_stime.tv_sec,
	rusage.ru_maxrss * getpagesize() / 1000);
    fprintf(lf, "Page faults with physical i/o: %d\n",
	rusage.ru_majflt);
#endif
    dumpMallocStats(lf);
    if (f)
	f(0);
    return 0;
}

void death(sig)
     int sig;
{
