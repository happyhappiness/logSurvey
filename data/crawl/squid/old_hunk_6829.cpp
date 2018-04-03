    runtime = tvSubDsec(squid_start, current_time);
    if (runtime == 0.0)
	runtime = 1.0;
    storeAppendPrintf(sentry, open_bracket);
    storeAppendPrintf(sentry, "{Squid Object Cache: Version %s}\n",
	version_string);
    storeAppendPrintf(sentry, "{Start Time:\t%s}\n",
	mkrfc1123(squid_start.tv_sec));
    storeAppendPrintf(sentry, "{Current Time:\t%s}\n",
	mkrfc1123(current_time.tv_sec));
    storeAppendPrintf(sentry, "{Connection information for %s:}\n",
	appname);
    storeAppendPrintf(sentry, "{\tNumber of HTTP requests received:\t%u}\n",
	Counter.client_http.requests);
    storeAppendPrintf(sentry, "{\tNumber of ICP messages received:\t%u}\n",
	Counter.icp.pkts_recv);
    storeAppendPrintf(sentry, "{\tNumber of ICP messages sent:\t%u}\n",
	Counter.icp.pkts_sent);
    storeAppendPrintf(sentry, "{\tRequest failure ratio:\t%5.2f%%\n",
	request_failure_ratio);

    storeAppendPrintf(sentry, "{\tHTTP requests per minute:\t%.1f}\n",
	Counter.client_http.requests / (runtime / 60.0));
    storeAppendPrintf(sentry, "{\tICP messages per minute:\t%.1f}\n",
	(Counter.icp.pkts_sent + Counter.icp.pkts_recv) / (runtime / 60.0));
    storeAppendPrintf(sentry, "{\tSelect loop called: %d times, %0.3f ms avg}\n",
	Counter.select_loops, 1000.0 * runtime / Counter.select_loops);

    storeAppendPrintf(sentry, "{Cache information for %s:}\n",
	appname);
    storeAppendPrintf(sentry, "{\tStorage Swap size:\t%d KB}\n",
	store_swap_size);
    storeAppendPrintf(sentry, "{\tStorage Mem size:\t%d KB}\n",
	store_mem_size >> 10);
    storeAppendPrintf(sentry, "{\tStorage LRU Expiration Age:\t%6.2f days}\n",
	(double) storeExpiredReferenceAge() / 86400.0);
    storeAppendPrintf(sentry, "{\tRequests given to unlinkd:\t%d}\n",
	Counter.unlink.requests);

    squid_getrusage(&rusage);
    cputime = rusage_cputime(&rusage);
    storeAppendPrintf(sentry, "{Resource usage for %s:}\n", appname);
    storeAppendPrintf(sentry, "{\tUP Time:\t%.3f seconds}\n", runtime);
    storeAppendPrintf(sentry, "{\tCPU Time:\t%.3f seconds}\n", cputime);
    storeAppendPrintf(sentry, "{\tCPU Usage:\t%.2f%%}\n",
	dpercent(cputime, runtime));
    storeAppendPrintf(sentry, "{\tMaximum Resident Size: %ld KB}\n",
	rusage_maxrss(&rusage));
    storeAppendPrintf(sentry, "{\tPage faults with physical i/o: %ld}\n",
	rusage_pagefaults(&rusage));

#if HAVE_MSTATS && HAVE_GNUMALLOC_H
    ms = mstats();
    storeAppendPrintf(sentry, "{Memory usage for %s via mstats():}\n",
	appname);
    storeAppendPrintf(sentry, "{\tTotal space in arena:  %6d KB}\n",
	ms.bytes_total >> 10);
    storeAppendPrintf(sentry, "{\tTotal free:            %6d KB %d%%}\n",
	ms.bytes_free >> 10, percent(ms.bytes_free, ms.bytes_total));
#elif HAVE_MALLINFO
    mp = mallinfo();
    storeAppendPrintf(sentry, "{Memory usage for %s via mallinfo():}\n",
	appname);
    storeAppendPrintf(sentry, "{\tTotal space in arena:  %6d KB}\n",
	mp.arena >> 10);
    storeAppendPrintf(sentry, "{\tOrdinary blocks:       %6d KB %6d blks}\n",
	mp.uordblks >> 10, mp.ordblks);
    storeAppendPrintf(sentry, "{\tSmall blocks:          %6d KB %6d blks}\n",
	mp.usmblks >> 10, mp.smblks);
    storeAppendPrintf(sentry, "{\tHolding blocks:        %6d KB %6d blks}\n",
	mp.hblkhd >> 10, mp.hblks);
    storeAppendPrintf(sentry, "{\tFree Small blocks:     %6d KB}\n",
	mp.fsmblks >> 10);
    storeAppendPrintf(sentry, "{\tFree Ordinary blocks:  %6d KB}\n",
	mp.fordblks >> 10);
    t = mp.uordblks + mp.usmblks + mp.hblkhd;
    storeAppendPrintf(sentry, "{\tTotal in use:          %6d KB %d%%}\n",
	t >> 10, percent(t, mp.arena));
    t = mp.fsmblks + mp.fordblks;
    storeAppendPrintf(sentry, "{\tTotal free:            %6d KB %d%%}\n",
	t >> 10, percent(t, mp.arena));
#if HAVE_EXT_MALLINFO
    storeAppendPrintf(sentry, "{\tmax size of small blocks:\t%d}\n", mp.mxfast);
    storeAppendPrintf(sentry, "{\tnumber of small blocks in a holding block:\t%d}\n",
	mp.nlblks);
    storeAppendPrintf(sentry, "{\tsmall block rounding factor:\t%d}\n", mp.grain);
    storeAppendPrintf(sentry, "{\tspace (including overhead) allocated in ord. blks:\t%d}\n"
	,mp.uordbytes);
    storeAppendPrintf(sentry, "{\tnumber of ordinary blocks allocated:\t%d}\n",
	mp.allocated);
    storeAppendPrintf(sentry, "{\tbytes used in maintaining the free tree:\t%d}\n",
	mp.treeoverhead);
#endif /* HAVE_EXT_MALLINFO */
#endif /* HAVE_MALLINFO */

    storeAppendPrintf(sentry, "{File descriptor usage for %s:}\n", appname);
    storeAppendPrintf(sentry, "{\tMaximum number of file descriptors:   %4d}\n",
	Squid_MaxFD);
    storeAppendPrintf(sentry, "{\tLargest file desc currently in use:   %4d}\n",
	Biggest_FD);
    storeAppendPrintf(sentry, "{\tNumber of file desc currently in use: %4d}\n",
	Number_FD);
    storeAppendPrintf(sentry, "{\tAvailable number of file descriptors: %4d}\n",
	Squid_MaxFD - Number_FD);
    storeAppendPrintf(sentry, "{\tReserved number of file descriptors:  %4d}\n",
	RESERVED_FD);

    storeAppendPrintf(sentry, "{Internal Data Structures:}\n");
    storeAppendPrintf(sentry, "{\t%6d StoreEntries}\n",
	memInUse(MEM_STOREENTRY));
    storeAppendPrintf(sentry, "{\t%6d StoreEntries with MemObjects}\n",
	memInUse(MEM_MEMOBJECT));
    storeAppendPrintf(sentry, "{\t%6d StoreEntries with MemObject Data}\n",
	memInUse(MEM_MEM_HDR));
    storeAppendPrintf(sentry, "{\t%6d Hot Object Cache Items}\n",
	meta_data.hot_vm);

    storeAppendPrintf(sentry, "{\t%-25.25s                      = %6d KB}\n",
	"StoreEntry Keys",
	meta_data.store_keys >> 10);

    storeAppendPrintf(sentry, "{\t%-25.25s %7d x %4d bytes = %6d KB}\n",
	"IPCacheEntry",
	meta_data.ipcache_count,
	(int) sizeof(ipcache_entry),
	(int) (meta_data.ipcache_count * sizeof(ipcache_entry) >> 10));

    storeAppendPrintf(sentry, "{\t%-25.25s %7d x %4d bytes = %6d KB}\n",
	"FQDNCacheEntry",
	meta_data.fqdncache_count,
	(int) sizeof(fqdncache_entry),
	(int) (meta_data.fqdncache_count * sizeof(fqdncache_entry) >> 10));

    storeAppendPrintf(sentry, "{\t%-25.25s %7d x %4d bytes = %6d KB}\n",
	"Hash link",
	hash_links_allocated,
	(int) sizeof(hash_link),
	(int) (hash_links_allocated * sizeof(hash_link) >> 10));

    storeAppendPrintf(sentry, "{\t%-25.25s %7d x %4d bytes = %6d KB}\n",
	"NetDB Peer Entries",
	meta_data.netdb_peers,
	(int) sizeof(struct _net_db_peer),
	             (int) (meta_data.netdb_peers * sizeof(struct _net_db_peer) >> 10));

    storeAppendPrintf(sentry, "{\t%-25.25s %7d x %4d bytes = %6d KB}\n",
	"ClientDB Entries",
	meta_data.client_info,
	client_info_sz,
	(int) (meta_data.client_info * client_info_sz >> 10));

    storeAppendPrintf(sentry, "{\t%-25.25s                      = %6d KB}\n",
	"Miscellaneous",
	meta_data.misc >> 10);

    storeAppendPrintf(sentry, "{\t%-25.25s                      = %6d KB}\n",
	"Total Accounted",
	statMemoryAccounted() >> 10);

#if XMALLOC_STATISTICS
    storeAppendPrintf(sentry, "{Memory allocation statistics}\n");
    malloc_statistics(info_get_mallstat, sentry);
#endif

    storeAppendPrintf(sentry, close_bracket);
}

static void