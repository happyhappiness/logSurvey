
	pthread_mutex_lock (&cache_lock);

	DBG ("vc = cache_search (%s)", name);
	vc = cache_search (name);

	if (vc == NULL)
	{
		DBG ("Did not find cache entry.");
		fprintf (fh, "-1 No such value");
	}
	else
	{
		DBG ("Found cache entry.");
		fprintf (fh, "%i", vc->values_num);
		for (i = 0; i < vc->values_num; i++)
		{
