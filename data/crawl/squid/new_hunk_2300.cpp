
    mp = mallinfo();

    fprintf(debug_log, "Memory usage for " APP_SHORTNAME " via mallinfo():\n");

    fprintf(debug_log, "\ttotal space in arena:  %6ld KB\n",
            (long)mp.arena >> 10);