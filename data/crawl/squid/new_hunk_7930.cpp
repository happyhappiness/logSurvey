	store_swap_size += (int) ((size + 1023) >> 10);
	objcount++;

	fprintf(new_log, "%s %s %d %d %d\n",
	    swapfile, url, (int) expires, (int) timestamp, (int) size);
	storeAddDiskRestore(url, sfileno, (int) size, expires, timestamp);
	CacheInfo->proto_newobject(CacheInfo,
	    CacheInfo->proto_id(url),
	    (int) size, TRUE);
    }

    fclose(old_log);
    fclose(new_log);
    if (rename(new_log_name, swaplog_file) < 0) {
	sprintf(tmp_error_buf, "storeRebuildFromDisk: rename: %s",
	    xstrerror());
	fatal(tmp_error_buf);
    }
    xfree(new_log_name);

    stop = cached_curtime = time(NULL);
    r = stop - start;
    debug(20, 1, "Finished rebuilding storage from disk image.\n");
    debug(20, 1, "  %7d Lines read from previous logfile.\n", linecount);
    debug(20, 1, "  %7d Objects loaded.\n", objcount);
    debug(20, 1, "  %7d Objects expired.\n", expcount);
    debug(20, 1, "  %7d Duplicate URLs purged.\n", dupcount);
    debug(20, 1, "  %7d Swapfile clashes avoided.\n", clashcount);
    debug(20, 1, "  Took %d seconds (%6.1lf objects/sec).\n",
	r > 0 ? r : 0, (double) objcount / (r > 0 ? r : 1));
    debug(20, 1, "  store_swap_size = %dk\n", store_swap_size);

    /* touch a timestamp file */
    sprintf(line_in, "%s/log-last-clean", swappath(0));
