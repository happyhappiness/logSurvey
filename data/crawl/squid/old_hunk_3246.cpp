    abort();
}


void
sigusr2_handle(int sig)
{
    static int state = 0;
    /* no debugs() here; bad things happen if the signal is delivered during _db_print() */

    if (state == 0) {
#if !MEM_GEN_TRACE
        Debug::parseOptions("ALL,7");
