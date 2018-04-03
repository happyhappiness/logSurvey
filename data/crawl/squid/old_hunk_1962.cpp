    static int DoneReadFD;
};

/* Inline code. TODO: make structued approach to inlining */
void
CommIO::NotifyIOCompleted()
{
    if (!Initialised)
        Initialise();

    if (!DoneSignalled) {
        DoneSignalled = true;
