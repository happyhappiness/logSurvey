    t = mp.uordblks + mp.usmblks + mp.hblkhd;

    storeAppendPrintf(sentry, "\tTotal in use:          %6d KB %d%%\n",
                      t >> 10, percent(t, mp.arena + mp.hblkhd));

    t = mp.fsmblks + mp.fordblks;

    storeAppendPrintf(sentry, "\tTotal free:            %6d KB %d%%\n",
                      t >> 10, percent(t, mp.arena + mp.hblkhd));

    t = mp.arena + mp.hblkhd;

