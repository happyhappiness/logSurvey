 		find_deltas(list, &list_size, window, depth, processed);
 		return;
 	}
+	if (progress > pack_to_stdout)
+		fprintf(stderr, "Delta compression using %d threads.\n",
+				delta_search_threads);
 
 	/* Partition the work amongst work threads. */
 	for (i = 0; i < delta_search_threads; i++) {