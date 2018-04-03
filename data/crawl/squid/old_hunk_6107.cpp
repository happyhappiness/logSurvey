fatal(const char *message)
{
    releaseServerSockets();
    /* check for store_rebuilding flag because fatal() is often
     * used in early initialization phases, long before we ever
     * get to the store log. */
    if (!store_rebuilding)
	storeDirWriteCleanLogs(0);
    fatal_common(message);
    exit(shutting_down ? 0 : 1);
