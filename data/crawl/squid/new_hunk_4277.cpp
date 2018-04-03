
    mp = mallinfo();

    storeAppendPrintf(sentry, "Memory usage for %s via mallinfo():\n",APP_SHORTNAME);

    storeAppendPrintf(sentry, "\tTotal space in arena:  %6ld KB\n",
                      (long)mp.arena >> 10);
