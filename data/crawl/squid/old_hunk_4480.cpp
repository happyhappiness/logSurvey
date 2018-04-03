    if (message)
        fatal_common(message);

    if (opt_catch_signals)
        storeDirWriteCleanLogs(0);
