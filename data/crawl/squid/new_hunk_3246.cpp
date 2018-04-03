    abort();
}

void
BroadcastSignalIfAny(int& sig)
{
    if (sig > 0) {
        if (IamCoordinatorProcess())
            Ipc::Coordinator::Instance()->broadcastSignal(sig);
        sig = -1;
    }
}

void
sigusr2_handle(int sig)
{
    static int state = 0;
    /* no debugs() here; bad things happen if the signal is delivered during _db_print() */

    DebugSignal = sig;

    if (state == 0) {
#if !MEM_GEN_TRACE
        Debug::parseOptions("ALL,7");
