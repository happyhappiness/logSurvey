    safe_free(debug_options)
    debug_options = xstrdup(Config.debugOptions);

    if (Config.retry.timeout < 5)
        fatal("minimum_retry_timeout must be at least 5 seconds");

    if (Config.retry.maxtries > 10)
        fatal("maximum_single_addr_tries cannot be larger than 10");

