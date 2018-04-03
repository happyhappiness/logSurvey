    else
        Config.appendDomainLen = 0;

    safe_free(debug_options)
    debug_options = xstrdup(Config.debugOptions);

    if (Config.retry.maxtries > 10)
        fatal("maximum_single_addr_tries cannot be larger than 10");

