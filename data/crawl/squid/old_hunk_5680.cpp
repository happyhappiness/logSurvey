	mp.fordblks >> 10);
    t = mp.uordblks + mp.usmblks + mp.hblkhd;
    storeAppendPrintf(sentry, "\tTotal in use:          %6d KB %d%%\n",
	t >> 10, percent(t, mp.arena));
    t = mp.fsmblks + mp.fordblks;
    storeAppendPrintf(sentry, "\tTotal free:            %6d KB %d%%\n",
	t >> 10, percent(t, mp.arena));
#if HAVE_EXT_MALLINFO
    storeAppendPrintf(sentry, "\tmax size of small blocks:\t%d\n", mp.mxfast);
    storeAppendPrintf(sentry, "\tnumber of small blocks in a holding block:\t%d\n",