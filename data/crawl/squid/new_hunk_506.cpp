    shutting_down = 1;

    releaseServerSockets();

    /* XXX: this should be turned into a callback-on-fatal, or
     * a mandatory-shutdown-event or something like that.
