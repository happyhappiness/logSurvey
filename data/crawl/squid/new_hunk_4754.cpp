    if (!flags.open)
        return;

#ifdef _SQUID_MSWIN_

    storeAppendPrintf(&dumpEntry, "%4d 0x%-8lX %-6.6s %4d %7d%c %7d%c %-21s %s\n",
                      fdNumber,
                      win32.handle,
#else
    storeAppendPrintf(&dumpEntry, "%4d %-6.6s %4d %7d%c %7d%c %-21s %s\n",
                      fdNumber,
#endif
                      fdTypeStr[type],
                      timeout_handler ? (int) (timeout - squid_curtime) / 60 : 0,
                      bytes_read,
