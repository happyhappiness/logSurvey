	    elapsed_msec = tvSubMsec(tv1, tv2);
	    t2s = tv2.tv_sec;
	    tmp = localtime(&t2s);
	    fprintf(stderr, "%d-%02d-%02d %02d:%02d:%02d [%d]: %ld.%03ld secs, %f KB/s\n",
		tmp->tm_year + 1900, tmp->tm_mon + 1, tmp->tm_mday,
		tmp->tm_hour, tmp->tm_min, tmp->tm_sec, i + 1,
		elapsed_msec / 1000, elapsed_msec % 1000,
		elapsed_msec ? (double) fsize / elapsed_msec : -1.0);
	    if (i == 0 || elapsed_msec < ping_min)
		ping_min = elapsed_msec;
	    if (i == 0 || elapsed_msec > ping_max)
