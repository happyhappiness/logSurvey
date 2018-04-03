fatal(const char *message)
{
    releaseServerSockets();
    /* check for store_dirs_rebuilding because fatal() is often
     * used in early initialization phases, long before we ever
     * get to the store log. */
    if (0 == store_dirs_rebuilding)
	storeDirWriteCleanLogs(0);
    fatal_common(message);
    exit(shutting_down ? 0 : 1);
