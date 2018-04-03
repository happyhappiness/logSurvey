    xm_deltat = current_dtime - xm_time;
    xm_time = current_dtime;
    storeAppendPrintf(sentry, "\nMemory allocation statistics\n");
    storeAppendPrintf(sentry, "Allocation Size\t Alloc Count\t Alloc Delta\t Allocs/sec \n");
    malloc_statistics(info_get_mallstat, sentry);
#endif
}