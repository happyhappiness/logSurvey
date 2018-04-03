    else
        Config.appendDomainLen = 0;

    if (Config.retry.maxtries > 10)
        fatal("maximum_single_addr_tries cannot be larger than 10");

    if (Config.retry.maxtries < 1) {
        debugs(3, 0, "WARNING: resetting 'maximum_single_addr_tries to 1");
        Config.retry.maxtries = 1;
    }

    requirePathnameExists("MIME Config Table", Config.mimeTablePathname);
