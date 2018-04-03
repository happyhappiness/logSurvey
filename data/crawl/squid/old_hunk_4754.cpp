    if (!flags.open)
        return;

    storeAppendPrintf(&dumpEntry, "%4d %-6.6s %4d %7d%c %7d%c %-21s %s\n",
                      fdNumber,
                      fdTypeStr[type],
                      timeout_handler ? (int) (timeout - squid_curtime) / 60 : 0,
                      bytes_read,
