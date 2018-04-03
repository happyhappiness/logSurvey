
    storeAppendPrintf(sentry, "\n%s:", descr);

    storeAppendPrintf(sentry, " (Cumulated time: %llu, %.2f sec)\n",
                      show->delta,
                      time_frame
                     );
