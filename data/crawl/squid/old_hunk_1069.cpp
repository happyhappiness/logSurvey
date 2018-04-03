}

static void
icpIncomingConnectionOpened(const Comm::ConnectionPointer &conn, int errNo)
{
    if (!Comm::IsConnOpen(conn))
        fatal("Cannot open ICP Port");
