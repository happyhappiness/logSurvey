}

static void
htcpIncomingConnectionOpened(int fd, int errNo)
{
    htcpInSocket = fd;

    if (htcpInSocket < 0)
        fatal("Cannot open HTCP Socket");

    Comm::SetSelect(htcpInSocket, COMM_SELECT_READ, htcpRecv, NULL, 0);

    debugs(31, 1, "Accepting HTCP messages on port " << Config.Port.htcp << ", FD " << htcpInSocket << ".");

    if (Config.Addrs.udp_outgoing.IsNoAddr())
        htcpOutSocket = htcpInSocket;
}

int
