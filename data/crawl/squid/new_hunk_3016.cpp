
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
        storeAppendPrintf(sentry, "\tmemPool unaccounted:   %6ld KB %3d%%\n",
                          (long)((t - mp_stats.TheMeter->alloc.level) >> 10),
                          Math::intPercent((t - mp_stats.TheMeter->alloc.level), t));
#endif

