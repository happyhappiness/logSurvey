    storeAppendPrintf(sentry, "Memory usage for %s via mallinfo():\n",APP_SHORTNAME);

    storeAppendPrintf(sentry, "\tTotal space in arena:  %6ld KB\n",
                      (long)mp.arena >> 10);

    storeAppendPrintf(sentry, "\tOrdinary blocks:       %6ld KB %6ld blks\n",
                      (long)mp.uordblks >> 10, (long)mp.ordblks);

    storeAppendPrintf(sentry, "\tSmall blocks:          %6ld KB %6ld blks\n",
                      (long)mp.usmblks >> 10, (long)mp.smblks);

    storeAppendPrintf(sentry, "\tHolding blocks:        %6ld KB %6ld blks\n",
                      (long)mp.hblkhd >> 10, (long)mp.hblks);

    storeAppendPrintf(sentry, "\tFree Small blocks:     %6ld KB\n",
                      (long)mp.fsmblks >> 10);

    storeAppendPrintf(sentry, "\tFree Ordinary blocks:  %6ld KB\n",
                      (long)mp.fordblks >> 10);

    t = mp.uordblks + mp.usmblks + mp.hblkhd;

    storeAppendPrintf(sentry, "\tTotal in use:          %6d KB %d%%\n",
                      t >> 10, Math::intPercent(t, mp.arena + mp.hblkhd));

    t = mp.fsmblks + mp.fordblks;

    storeAppendPrintf(sentry, "\tTotal free:            %6d KB %d%%\n",
                      t >> 10, Math::intPercent(t, mp.arena + mp.hblkhd));

    t = mp.arena + mp.hblkhd;

    storeAppendPrintf(sentry, "\tTotal size:            %6d KB\n",
                      t >> 10);

#if HAVE_STRUCT_MALLINFO_MXFAST

    storeAppendPrintf(sentry, "\tmax size of small blocks:\t%d\n", mp.mxfast);

    storeAppendPrintf(sentry, "\tnumber of small blocks in a holding block:\t%d\n",
                      mp.nlblks);

    storeAppendPrintf(sentry, "\tsmall block rounding factor:\t%d\n", mp.grain);

    storeAppendPrintf(sentry, "\tspace (including overhead) allocated in ord. blks:\t%d\n"
                      ,mp.uordbytes);

    storeAppendPrintf(sentry, "\tnumber of ordinary blocks allocated:\t%d\n",
                      mp.allocated);

    storeAppendPrintf(sentry, "\tbytes used in maintaining the free tree:\t%d\n",
                      mp.treeoverhead);

#endif /* HAVE_STRUCT_MALLINFO_MXFAST */
#endif /* HAVE_MALLINFO */
