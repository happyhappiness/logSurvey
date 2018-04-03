    t = mp.fsmblks + mp.fordblks;
    fprintf(f, "\tTotal free:            %6d KB %d%%\n",
	t >> 10, percent(t, mp.arena));
#if HAVE_EXT_MALLINFO
    fprintf(f, "\tmax size of small blocks:\t%d\n",
	mp.mxfast);