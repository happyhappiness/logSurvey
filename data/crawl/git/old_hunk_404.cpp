	else if (num_threads < 0)
		die(_("invalid number of threads specified (%d)"), num_threads);
#else
	num_threads = 0;
#endif

