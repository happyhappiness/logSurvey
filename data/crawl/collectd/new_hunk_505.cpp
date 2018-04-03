
	pthread_mutex_lock (&cache_lock);

	DEBUG ("vc = cache_search (%s)", name);
	vc = cache_search (name);

	if (vc == NULL)
	{
		DEBUG ("Did not find cache entry.");
		fprintf (fh, "-1 No such value");
	}
	else
	{
		DEBUG ("Found cache entry.");
		fprintf (fh, "%i", vc->values_num);
		for (i = 0; i < vc->values_num; i++)
		{
