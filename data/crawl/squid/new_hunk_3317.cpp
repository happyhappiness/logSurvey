    else
        Config.appendDomainLen = 0;

    if (Config.connect_retries > 10) {
        debugs(0,DBG_CRITICAL, "WARNING: connect_retries cannot be larger than 10. Resetting to 10.");
        Config.connect_retries = 10;
    }

    requirePathnameExists("MIME Config Table", Config.mimeTablePathname);
