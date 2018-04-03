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
