
    fprintf(debug_log, "Memory usage for %s via mallinfo():\n", appname);

    fprintf(debug_log, "\ttotal space in arena:  %6ld KB\n",
            (long)mp.arena >> 10);

    fprintf(debug_log, "\tOrdinary blocks:       %6ld KB %6ld blks\n",
            (long)mp.uordblks >> 10, (long)mp.ordblks);

    fprintf(debug_log, "\tSmall blocks:          %6ld KB %6ld blks\n",
            (long)mp.usmblks >> 10, (long)mp.smblks);

    fprintf(debug_log, "\tHolding blocks:        %6ld KB %6ld blks\n",
            (long)mp.hblkhd >> 10, (long)mp.hblks);

    fprintf(debug_log, "\tFree Small blocks:     %6ld KB\n",
            (long)mp.fsmblks >> 10);

    fprintf(debug_log, "\tFree Ordinary blocks:  %6ld KB\n",
            (long)mp.fordblks >> 10);

    t = mp.uordblks + mp.usmblks + mp.hblkhd;

