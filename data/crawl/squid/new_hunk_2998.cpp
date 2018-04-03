}

static void
htcpIncomingConnectionOpened(int)
{
    if (!Comm::IsConnOpen(htcpIncomingConn))
        fatal("Cannot open HTCP Socket");

    commSetSelect(htcpIncomingConn->fd, COMM_SELECT_READ, htcpRecv, NULL, 0);

    debugs(31, DBG_CRITICAL, "Accepting HTCP messages on " << htcpIncomingConn->local);

    if (Config.Addrs.udp_outgoing.IsNoAddr()) {
        htcpOutgoingConn = htcpIncomingConn;
        debugs(31, DBG_IMPORTANT, "Sending HTCP messages from " << htcpOutgoingConn->local);
    }
}

int
