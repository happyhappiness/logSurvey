    storeAppendPrintf(e, "Idle pool limit: %.2f MB\n", toMB(mp_total.mem_idle_limit));
    /* limits */
    storeAppendPrintf(e, "Total Pools created: %d\n", mp_total.tot_pools_alloc);
    storeAppendPrintf(e, "Pools ever used:     %d (shown above)\n", mp_total.tot_pools_alloc - not_used);
    storeAppendPrintf(e, "Currently in use:    %d\n", mp_total.tot_pools_inuse);
}
