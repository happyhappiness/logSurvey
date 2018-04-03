#endif

    storeAppendPrintf(sentry, "Start Time:\t%s\n",
                      mkrfc1123(squid_start.tv_sec));

    storeAppendPrintf(sentry, "Current Time:\t%s\n",
                      mkrfc1123(current_time.tv_sec));

    storeAppendPrintf(sentry, "Connection information for %s:\n",APP_SHORTNAME);

    storeAppendPrintf(sentry, "\tNumber of clients accessing cache:\t%u\n",
                      statCounter.client_http.clients);

    storeAppendPrintf(sentry, "\tNumber of HTTP requests received:\t%u\n",
                      statCounter.client_http.requests);

    storeAppendPrintf(sentry, "\tNumber of ICP messages received:\t%u\n",
                      statCounter.icp.pkts_recv);

    storeAppendPrintf(sentry, "\tNumber of ICP messages sent:\t%u\n",
                      statCounter.icp.pkts_sent);

    storeAppendPrintf(sentry, "\tNumber of queued ICP replies:\t%u\n",
                      statCounter.icp.replies_queued);

#if USE_HTCP

    storeAppendPrintf(sentry, "\tNumber of HTCP messages received:\t%u\n",
                      statCounter.htcp.pkts_recv);

    storeAppendPrintf(sentry, "\tNumber of HTCP messages sent:\t%u\n",
                      statCounter.htcp.pkts_sent);

#endif

    storeAppendPrintf(sentry, "\tRequest failure ratio:\t%5.2f\n",
                      request_failure_ratio);

    storeAppendPrintf(sentry, "\tAverage HTTP requests per minute since start:\t%.1f\n",
                      statCounter.client_http.requests / (runtime / 60.0));

    storeAppendPrintf(sentry, "\tAverage ICP messages per minute since start:\t%.1f\n",
                      (statCounter.icp.pkts_sent + statCounter.icp.pkts_recv) / (runtime / 60.0));

    storeAppendPrintf(sentry, "\tSelect loop called: %ld times, %0.3f ms avg\n",
                      statCounter.select_loops, 1000.0 * runtime / statCounter.select_loops);

    storeAppendPrintf(sentry, "Cache information for %s:\n",APP_SHORTNAME);

    storeAppendPrintf(sentry, "\tHits as %% of all requests:\t5min: %3.1f%%, 60min: %3.1f%%\n",
                      statRequestHitRatio(5),
                      statRequestHitRatio(60));

    storeAppendPrintf(sentry, "\tHits as %% of bytes sent:\t5min: %3.1f%%, 60min: %3.1f%%\n",
                      statByteHitRatio(5),
                      statByteHitRatio(60));

    storeAppendPrintf(sentry, "\tMemory hits as %% of hit requests:\t5min: %3.1f%%, 60min: %3.1f%%\n",
                      statRequestHitMemoryRatio(5),
                      statRequestHitMemoryRatio(60));

    storeAppendPrintf(sentry, "\tDisk hits as %% of hit requests:\t5min: %3.1f%%, 60min: %3.1f%%\n",
                      statRequestHitDiskRatio(5),
                      statRequestHitDiskRatio(60));

    storeAppendPrintf(sentry, "\tStorage Swap size:\t%lu KB\n",
                      store_swap_size);

    storeAppendPrintf(sentry, "\tStorage Swap capacity:\t%4.1f%% used, %4.1f%% free\n",
                      Math::doublePercent(store_swap_size, Store::Root().maxSize()),
                      Math::doublePercent((Store::Root().maxSize() - store_swap_size), Store::Root().maxSize()));


    storeAppendPrintf(sentry, "\tStorage Mem size:\t%lu KB\n",
                      (unsigned long)(mem_node::StoreMemSize() >> 10));

    double mFree = 0.0;
    if (mem_node::InUseCount() <= store_pages_max)
        mFree = Math::doublePercent((store_pages_max - mem_node::InUseCount()), store_pages_max);
    storeAppendPrintf(sentry, "\tStorage Mem capacity:\t%4.1f%% used, %4.1f%% free\n",
                      Math::doublePercent(mem_node::InUseCount(), store_pages_max),
                      mFree);

    storeAppendPrintf(sentry, "\tMean Object Size:\t%0.2f KB\n",
                      n_disk_objects ? (double) store_swap_size / n_disk_objects : 0.0);

    storeAppendPrintf(sentry, "\tRequests given to unlinkd:\t%ld\n",
                      (long)statCounter.unlink.requests);

    storeAppendPrintf(sentry, "Median Service Times (seconds)  5 min    60 min:\n");

    storeAppendPrintf(sentry, "\tHTTP Requests (All):  %8.5f %8.5f\n",
                      statPctileSvc(0.5, 5, PCTILE_HTTP) / 1000.0,
                      statPctileSvc(0.5, 60, PCTILE_HTTP) / 1000.0);

    storeAppendPrintf(sentry, "\tCache Misses:         %8.5f %8.5f\n",
                      statPctileSvc(0.5, 5, PCTILE_MISS) / 1000.0,
                      statPctileSvc(0.5, 60, PCTILE_MISS) / 1000.0);

    storeAppendPrintf(sentry, "\tCache Hits:           %8.5f %8.5f\n",
                      statPctileSvc(0.5, 5, PCTILE_HIT) / 1000.0,
                      statPctileSvc(0.5, 60, PCTILE_HIT) / 1000.0);

    storeAppendPrintf(sentry, "\tNear Hits:            %8.5f %8.5f\n",
                      statPctileSvc(0.5, 5, PCTILE_NH) / 1000.0,
                      statPctileSvc(0.5, 60, PCTILE_NH) / 1000.0);

    storeAppendPrintf(sentry, "\tNot-Modified Replies: %8.5f %8.5f\n",
                      statPctileSvc(0.5, 5, PCTILE_NM) / 1000.0,
                      statPctileSvc(0.5, 60, PCTILE_NM) / 1000.0);

    storeAppendPrintf(sentry, "\tDNS Lookups:          %8.5f %8.5f\n",
                      statPctileSvc(0.5, 5, PCTILE_DNS) / 1000.0,
                      statPctileSvc(0.5, 60, PCTILE_DNS) / 1000.0);

    storeAppendPrintf(sentry, "\tICP Queries:          %8.5f %8.5f\n",
                      statPctileSvc(0.5, 5, PCTILE_ICP_QUERY) / 1000000.0,
                      statPctileSvc(0.5, 60, PCTILE_ICP_QUERY) / 1000000.0);

    squid_getrusage(&rusage);

    cputime = rusage_cputime(&rusage);

    storeAppendPrintf(sentry, "Resource usage for %s:\n", APP_SHORTNAME);

    storeAppendPrintf(sentry, "\tUP Time:\t%.3f seconds\n", runtime);

    storeAppendPrintf(sentry, "\tCPU Time:\t%.3f seconds\n", cputime);

    storeAppendPrintf(sentry, "\tCPU Usage:\t%.2f%%\n",
                      Math::doublePercent(cputime, runtime));

    storeAppendPrintf(sentry, "\tCPU Usage, 5 minute avg:\t%.2f%%\n",
                      statCPUUsage(5));

    storeAppendPrintf(sentry, "\tCPU Usage, 60 minute avg:\t%.2f%%\n",
                      statCPUUsage(60));

#if HAVE_SBRK

    storeAppendPrintf(sentry, "\tProcess Data Segment Size via sbrk(): %lu KB\n",
                      (unsigned long) (((char *) sbrk(0) - (char *) sbrk_start) >> 10));

#endif

    storeAppendPrintf(sentry, "\tMaximum Resident Size: %ld KB\n",
                      (long)rusage_maxrss(&rusage));

    storeAppendPrintf(sentry, "\tPage faults with physical i/o: %ld\n",
                      (long)rusage_pagefaults(&rusage));

#if HAVE_MSTATS && HAVE_GNUMALLOC_H

    ms = mstats();

    storeAppendPrintf(sentry, "Memory usage for %s via mstats():\n",APP_SHORTNAME);

    storeAppendPrintf(sentry, "\tTotal space in arena:  %6ld KB\n",
                      (long)(ms.bytes_total >> 10));

    storeAppendPrintf(sentry, "\tTotal free:            %6ld KB %d%%\n",
                      (long)(ms.bytes_free >> 10), Math::intPercent(ms.bytes_free, ms.bytes_total));

#elif HAVE_MALLINFO && HAVE_STRUCT_MALLINFO

    mp = mallinfo();

    storeAppendPrintf(sentry, "Memory usage for %s via mallinfo():\n",APP_SHORTNAME);

    storeAppendPrintf(sentry, "\tTotal space in arena:  %6ld KB\n",
                      (long)(mp.arena >> 10));

    storeAppendPrintf(sentry, "\tOrdinary blocks:       %6ld KB %6ld blks\n",
                      (long)(mp.uordblks >> 10), (long)mp.ordblks);

    storeAppendPrintf(sentry, "\tSmall blocks:          %6ld KB %6ld blks\n",
                      (long)(mp.usmblks >> 10), (long)mp.smblks);

    storeAppendPrintf(sentry, "\tHolding blocks:        %6ld KB %6ld blks\n",
                      (long)(mp.hblkhd >> 10), (long)mp.hblks);

    storeAppendPrintf(sentry, "\tFree Small blocks:     %6ld KB\n",
                      (long)(mp.fsmblks >> 10));

    storeAppendPrintf(sentry, "\tFree Ordinary blocks:  %6ld KB\n",
                      (long)(mp.fordblks >> 10));

    t = mp.uordblks + mp.usmblks + mp.hblkhd;

    storeAppendPrintf(sentry, "\tTotal in use:          %6ld KB %d%%\n",
                      (long)(t >> 10), Math::intPercent(t, mp.arena + mp.hblkhd));

    t = mp.fsmblks + mp.fordblks;

    storeAppendPrintf(sentry, "\tTotal free:            %6ld KB %d%%\n",
                      (long)(t >> 10), Math::intPercent(t, mp.arena + mp.hblkhd));

    t = mp.arena + mp.hblkhd;

    storeAppendPrintf(sentry, "\tTotal size:            %6ld KB\n",
                      (long)(t >> 10));

#if HAVE_STRUCT_MALLINFO_MXFAST

    storeAppendPrintf(sentry, "\tmax size of small blocks:\t%d\n", mp.mxfast);

    storeAppendPrintf(sentry, "\tnumber of small blocks in a holding block:\t%ld\n",
                      (long)mp.nlblks);

    storeAppendPrintf(sentry, "\tsmall block rounding factor:\t%ld\n", (long)mp.grain);

    storeAppendPrintf(sentry, "\tspace (including overhead) allocated in ord. blks:\t%ld\n",
                      (long)mp.uordbytes);

    storeAppendPrintf(sentry, "\tnumber of ordinary blocks allocated:\t%ld\n",
                      (long)mp.allocated);

    storeAppendPrintf(sentry, "\tbytes used in maintaining the free tree:\t%ld\n",
                      (long)mp.treeoverhead);

#endif /* HAVE_STRUCT_MALLINFO_MXFAST */
#endif /* HAVE_MALLINFO */
