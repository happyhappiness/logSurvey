		find_deltas(list, &list_size, window, depth, processed);
		return;
	}

	/* Partition the work amongst work threads. */
	for (i = 0; i < delta_search_threads; i++) {