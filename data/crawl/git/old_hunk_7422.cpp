#ifdef THREADED_DELTA_SEARCH
	if (!delta_search_threads)	/* --threads=0 means autodetect */
		delta_search_threads = online_cpus();
#endif

	prepare_packed_git();