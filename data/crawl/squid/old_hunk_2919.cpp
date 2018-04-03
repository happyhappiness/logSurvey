
#if !(HAVE_MSTATS && HAVE_GNUMALLOC_H) && HAVE_MALLINFO && HAVE_STRUCT_MALLINFO

    storeAppendPrintf(sentry, "\tTotal accounted:       %6ld KB %3d%%\n",
                      (long)(statMemoryAccounted() >> 10), Math::intPercent(statMemoryAccounted(), t));

#else

    storeAppendPrintf(sentry, "\tTotal accounted:       %6ld KB\n",
                      (long)(statMemoryAccounted() >> 10));

#endif
    {
        MemPoolGlobalStats mp_stats;
        memPoolGetGlobalStats(&mp_stats);
#if !(HAVE_MSTATS && HAVE_GNUMALLOC_H) && HAVE_MALLINFO && HAVE_STRUCT_MALLINFO

        storeAppendPrintf(sentry, "\tmemPool accounted:     %6ld KB %3d%%\n",
                          (long)(mp_stats.TheMeter->alloc.level >> 10),
                          Math::intPercent(mp_stats.TheMeter->alloc.level, t));

        int iFree = 0;
        if (t >= mp_stats.TheMeter->alloc.level)
            iFree = Math::intPercent((t - mp_stats.TheMeter->alloc.level), t);
        storeAppendPrintf(sentry, "\tmemPool unaccounted:   %6ld KB %3d%%\n",
                          (long)((t - mp_stats.TheMeter->alloc.level) >> 10), iFree);
#endif

        storeAppendPrintf(sentry, "\tmemPoolAlloc calls: %9.0f\n",
                          mp_stats.TheMeter->gb_saved.count);
        storeAppendPrintf(sentry, "\tmemPoolFree calls:  %9.0f\n",
                          mp_stats.TheMeter->gb_freed.count);
    }

    storeAppendPrintf(sentry, "File descriptor usage for %s:\n", APP_SHORTNAME);
    storeAppendPrintf(sentry, "\tMaximum number of file descriptors:   %4d\n",
                      Squid_MaxFD);
    storeAppendPrintf(sentry, "\tLargest file desc currently in use:   %4d\n",
                      Biggest_FD);
    storeAppendPrintf(sentry, "\tNumber of file desc currently in use: %4d\n",
                      Number_FD);
    storeAppendPrintf(sentry, "\tFiles queued for open:                %4d\n",
                      Opening_FD);
    storeAppendPrintf(sentry, "\tAvailable number of file descriptors: %4d\n",
                      fdNFree());
    storeAppendPrintf(sentry, "\tReserved number of file descriptors:  %4d\n",
                      RESERVED_FD);
    storeAppendPrintf(sentry, "\tStore Disk files open:                %4d\n",
                      store_open_disk_fd);

    storeAppendPrintf(sentry, "Internal Data Structures:\n");
    storeAppendPrintf(sentry, "\t%6lu StoreEntries\n",
                      (unsigned long)StoreEntry::inUseCount());
    storeAppendPrintf(sentry, "\t%6lu StoreEntries with MemObjects\n",
                      (unsigned long)MemObject::inUseCount());
    storeAppendPrintf(sentry, "\t%6ld Hot Object Cache Items\n",
                      (long)hot_obj_count);
    storeAppendPrintf(sentry, "\t%6ld on-disk objects\n",
                      (long)n_disk_objects);

#if XMALLOC_STATISTICS

    xm_deltat = current_dtime - xm_time;
