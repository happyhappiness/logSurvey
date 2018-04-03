    // decide whether to use a shared memory cache if the user did not specify
    if (!Config.memShared.configured()) {
        Config.memShared.configure(AtomicOperationsSupported &&
            UsingSmp() && Config.memMaxSize > 0);
    } else
    if (Config.memShared && !AtomicOperationsSupported) {
        // bail if the user wants shared memory cache but we cannot support it
        fatal("memory_cache_shared is on, but no support for atomic operations detected");
    }

    if (!Config.memShared)
