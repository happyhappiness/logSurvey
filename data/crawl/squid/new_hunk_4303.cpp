    shut_down(0);
}

/// \ingroup CacheManagerInternal
static void
cachemgrReconfigure(StoreEntry * sentry)
{
    debug(16, 0) ("Reconfigure by command.\n");
    storeAppendPrintf(sentry, "Reconfiguring Squid Process ....");
    reconfigure(SIGHUP);
}

/// \ingroup CacheManagerInternal
static void
cachemgrOfflineToggle(StoreEntry * sentry)
