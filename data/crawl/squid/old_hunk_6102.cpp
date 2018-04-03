{
    struct rusage rusage;
    squid_getrusage(&rusage);
    fprintf(debug_log, "CPU Usage: %.3f seconds\n", rusage_cputime(&rusage));
    fprintf(debug_log, "Maximum Resident Size: %d KB\n",
	rusage_maxrss(&rusage));
    fprintf(debug_log, "Page faults with physical i/o: %d\n",