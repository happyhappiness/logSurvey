
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

