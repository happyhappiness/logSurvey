    storeAppendPrintf(sentry, "Squid Object Cache: Version %s\n",
                      version_string);

    storeAppendPrintf(sentry, "Build Info: " SQUID_BUILD_INFO "\n");

#if _SQUID_WINDOWS_
    if (WIN32_run_mode == _WIN_SQUID_RUN_MODE_SERVICE) {
        storeAppendPrintf(sentry,"\nRunning as %s Windows System Service on %s\n",