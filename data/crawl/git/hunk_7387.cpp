 #ifdef THREADED_DELTA_SEARCH
 	if (!delta_search_threads)	/* --threads=0 means autodetect */
 		delta_search_threads = online_cpus();
-	if (progress)
-		fprintf(stderr, "Using %d pack threads.\n",
-			delta_search_threads);
 #endif
 
 	prepare_packed_git();