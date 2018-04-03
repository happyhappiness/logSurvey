                          i ? (1 << (i - 1)) + 1 : 1,
                          1 << i,
                          IOStats.Gopher.read_hist[i],
                          percent(IOStats.Gopher.read_hist[i], IOStats.Gopher.reads));
    }

    storeAppendPrintf(sentry, "\n");
