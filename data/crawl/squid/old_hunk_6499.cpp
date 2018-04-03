	}
	if (next_i >= 0) {
	    cur_time = next_time;
	    /*fprintf(stderr, "%2d time: %d %s", next_i, (int)cur_time, ctime(&cur_time));*/
	    if (next_i == 0)
		cacheFetch(us, fis[next_i]->entry);
	    else
