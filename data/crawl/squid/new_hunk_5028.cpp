                      "  (CPU times are in arbitrary units, most probably in CPU clock ticks)\n");
    storeAppendPrintf(sentry,
                      "Probe Name\t Event Count\t last Interval \t Avg Interval \t since squid start \t (since system boot) \n");
    storeAppendPrintf(sentry, "Total\t %lu\t %" PRIu64 " \t %" PRIu64 " \t %" PRIu64 " \t %" PRIu64 "\n",
                      (long unsigned) xprof_events,
                      xprof_delta,
                      xprof_average_delta,
