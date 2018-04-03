		return;
	}
	if (progress > pack_to_stdout)
		fprintf(stderr, "Delta compression using up to %d threads.\n",
				delta_search_threads);

	/* Partition the work amongst work threads. */