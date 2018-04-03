	struct tm tm;
	int offset, eastwest;

	t = time;
	localtime_r(&t, &tm);
	t_local = tm_to_time_t(&tm);
