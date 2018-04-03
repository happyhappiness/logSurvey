	Config.appendDomainLen = 0;
    safe_free(debug_options)
	debug_options = xstrdup(Config.debugOptions);
    if (Config.retry.timeout < 5)
	fatal("minimum_retry_timeout must be at least 5 seconds");
    if (Config.retry.maxtries > 10)
	fatal("maximum_single_addr_tries cannot be larger than 10");
    if (Config.retry.maxtries < 1) {
	Config.retry.maxtries = 1;
	debug(3, 0) ("WARNING: resetting 'maximum_single_addr_tries to 1\n");
    }
}

/* Parse a time specification from the config file.  Store the
