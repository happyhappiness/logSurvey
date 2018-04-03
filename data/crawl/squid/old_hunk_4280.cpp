
    mp = mallinfo();

    fprintf(debug_log, "Memory usage for %s via mallinfo():\n", appname);

    fprintf(debug_log, "\ttotal space in arena:  %6ld KB\n",
            (long)mp.arena >> 10);
