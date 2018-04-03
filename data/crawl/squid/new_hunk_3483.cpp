                          i ? (1 << (i - 1)) + 1 : 1,
                          1 << i,
                          IOStats.Ftp.read_hist[i],
                          Math::intPercent(IOStats.Ftp.read_hist[i], IOStats.Ftp.reads));
    }

    storeAppendPrintf(sentry, "\n");
