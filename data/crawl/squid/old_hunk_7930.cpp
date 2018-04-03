	store_swap_size += (int) ((size + 1023) >> 10);
	objcount++;

	fprintf(swaplog_tmp_stream, "FILE: %s URL: %s %d %d %d\n",
	    swapfile, url, (int) expires, (int) timestamp, (int) size);
	storeAddDiskRestore(url, sfileno, (int) size, expires, timestamp);
	CacheInfo->proto_newobject(CacheInfo,
	    CacheInfo->proto_id(url),
	    (int) size, TRUE);
    }

    fflush(swaplog_tmp_stream);
    stop = cached_curtime = time(NULL);
    r = stop - start;
    /* swapfileno = sfileno; */
    /* PBD: Start swapfileno at zero, so that old swap files are overwritten */
    debug(0, 1, "Finished rebuilding storage from disk image.\n");
    debug(0, 1, "  %7d Lines read from previous logfile.\n", linecount);
    debug(0, 1, "  %7d Objects loaded.\n", objcount);
    debug(0, 1, "  %7d Objects expired.\n", expcount);
    debug(0, 1, "  %7d Duplicate URLs purged.\n", dupcount);
    debug(0, 1, "  %7d Swapfile clashes avoided.\n", clashcount);
    debug(0, 1, "  Took %d seconds (%6.1lf objects/sec).\n",
	r > 0 ? r : 0, (double) objcount / (r > 0 ? r : 1));
    debug(0, 1, "  store_swap_size = %dk\n", store_swap_size);

    /* touch a timestamp file */
    sprintf(line_in, "%s/log-last-clean", swappath(0));
