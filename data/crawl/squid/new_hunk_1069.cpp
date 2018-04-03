}

static void
icpIncomingConnectionOpened(const Comm::ConnectionPointer &conn, int)
{
    if (!Comm::IsConnOpen(conn))
        fatal("Cannot open ICP Port");
