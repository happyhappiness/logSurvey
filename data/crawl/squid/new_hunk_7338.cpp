void
fatal(const char *message)
{
    releaseServerSockets();
    /* check for store_rebuilding flag because fatal() is often
     * used in early initialization phases, long before we ever
     * get to the store log. */
