    t = mp.fsmblks + mp.fordblks;
    fprintf(debug_log, "\tTotal free:            %6d KB %d%%\n",
	t >> 10, percent(t, mp.arena));
#if HAVE_EXT_MALLINFO
    fprintf(debug_log, "\tmax size of small blocks:\t%d\n",
	mp.mxfast);
    fprintf(debug_log, "\tnumber of small blocks in a holding block:\t%d\n",
