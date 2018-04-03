
        storeAppendPrintf(sentry, "\tmemPool accounted:     %6d KB %3d%%\n",
                          (int) mp_stats.TheMeter->alloc.level >> 10,
                          Math::intPercent(mp_stats.TheMeter->alloc.level, t));
        storeAppendPrintf(sentry, "\tmemPool unaccounted:   %6d KB %3d%%\n",
                          (t - (int) mp_stats.TheMeter->alloc.level) >> 10,
                          Math::intPercent((t - mp_stats.TheMeter->alloc.level), t));
#endif

        storeAppendPrintf(sentry, "\tmemPoolAlloc calls: %9.0f\n",
