                          i ? (1 << (i - 1)) + 1 : 1,
                          1 << i,
                          IOStats.Http.read_hist[i],
                          Math::intPercent(IOStats.Http.read_hist[i], IOStats.Http.reads));
    }

    storeAppendPrintf(sentry, "\n");
