	    }
	}
	if (next_i >= 0) {
	    /* skip access log entries recorder before creation of swap.state */
	    if (cur_time > 0 || next_i > 0) {
		cur_time = next_time;
		/*fprintf(stderr, "%2d time: %d %s", next_i, (int)cur_time, ctime(&cur_time));*/
		if (next_i == 0)
		    cacheFetch(us, fis[next_i]->entry);
		else
		    cacheUpdateStore(them, fis[next_i]->entry, 0);
	    }
	    fileIteratorAdvance(fis[next_i]);
	}
    } while (active_fi_count);