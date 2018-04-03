    t = mp.fsmblks + mp.fordblks;
    fprintf(f, "\tTotal free:            %6d KB %d%%\n",
	t >> 10, percent(t, mp.arena));
#ifdef WE_DONT_USE_KEEP
    fprintf(f, "\tKeep option:           %6d KB\n",
	mp.keepcost >> 10);
#endif
#if HAVE_EXT_MALLINFO
    fprintf(f, "\tmax size of small blocks:\t%d\n",
	mp.mxfast);