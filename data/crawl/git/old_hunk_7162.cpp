	if (!pack_to_stdout && thin)
		die("--thin cannot be used to build an indexable pack.");

#ifdef THREADED_DELTA_SEARCH
	if (!delta_search_threads)	/* --threads=0 means autodetect */
		delta_search_threads = online_cpus();
