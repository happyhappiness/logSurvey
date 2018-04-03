}

static void
dumpMallocStats()
{
#if HAVE_MALLINFO
    struct mallinfo mp;
    int t;
    if (!do_mallinfo)
	return;
    mp = mallinfo();
    fprintf(debug_log, "Memory usage for %s via mallinfo():\n", appname);
    fprintf(debug_log, "\ttotal space in arena:  %6d KB\n",
	mp.arena >> 10);
    fprintf(debug_log, "\tOrdinary blocks:       %6d KB %6d blks\n",
	mp.uordblks >> 10, mp.ordblks);
    fprintf(debug_log, "\tSmall blocks:          %6d KB %6d blks\n",
	mp.usmblks >> 10, mp.smblks);
    fprintf(debug_log, "\tHolding blocks:        %6d KB %6d blks\n",
	mp.hblkhd >> 10, mp.hblks);
    fprintf(debug_log, "\tFree Small blocks:     %6d KB\n",
	mp.fsmblks >> 10);
    fprintf(debug_log, "\tFree Ordinary blocks:  %6d KB\n",
	mp.fordblks >> 10);
    t = mp.uordblks + mp.usmblks + mp.hblkhd;
    fprintf(debug_log, "\tTotal in use:          %6d KB %d%%\n",
	t >> 10, percent(t, mp.arena));
    t = mp.fsmblks + mp.fordblks;
    fprintf(debug_log, "\tTotal free:            %6d KB %d%%\n",
	t >> 10, percent(t, mp.arena));
#if HAVE_EXT_MALLINFO
    fprintf(debug_log, "\tmax size of small blocks:\t%d\n",
	mp.mxfast);
    fprintf(debug_log, "\tnumber of small blocks in a holding block:\t%d\n",
	mp.nlblks);
    fprintf(debug_log, "\tsmall block rounding factor:\t%d\n",
	mp.grain);
    fprintf(debug_log, "\tspace (including overhead) allocated in ord. blks:\t%d\n",
	mp.uordbytes);
    fprintf(debug_log, "\tnumber of ordinary blocks allocated:\t%d\n",
	mp.allocated);
    fprintf(debug_log, "\tbytes used in maintaining the free tree:\t%d\n",
	mp.treeoverhead);
#endif /* HAVE_EXT_MALLINFO */
#if PRINT_MMAP
