
	pthread_mutex_lock (&cache_lock);

	vc = cache_search (name);

	fprintf (fh, "%i", vc->values_num);
	for (i = 0; i < vc->values_num; i++)
	{
		if (vc->gauge[i] == NAN)
			fprintf (fh, " NaN");
		else
			fprintf (fh, " %12e", vc->gauge[i]);
	}

	/* Free the mutex as soon as possible and definitely before flushing */
