{
    debugs(49, 5, "snmpConnectionOpen: Called");

    if (Config.Port.snmp <= 0)
        return;

    snmpIncomingConn = new Comm::Connection;
    snmpIncomingConn->local = Config.Addrs.snmp_incoming;
    snmpIncomingConn->local.SetPort(Config.Port.snmp);

    if (!Ip::EnableIpv6 && !snmpIncomingConn->local.SetIPv4()) {
        debugs(49, DBG_CRITICAL, "ERROR: IPv6 is disabled. " << snmpIncomingConn->local << " is not an IPv4 address.");
        fatal("SNMP port cannot be opened.");
    }
    /* split-stack for now requires IPv4-only SNMP */
    if (Ip::EnableIpv6&IPV6_SPECIAL_SPLITSTACK && snmpIncomingConn->local.IsAnyAddr()) {
        snmpIncomingConn->local.SetIPv4();
    }

    AsyncCall::Pointer call = asyncCall(49, 2, "snmpIncomingConnectionOpened",
                                        SnmpListeningStartedDialer(&snmpPortOpened));
    Ipc::StartListening(SOCK_DGRAM, IPPROTO_UDP, snmpIncomingConn, Ipc::fdnInSnmpSocket, call);

    if (!Config.Addrs.snmp_outgoing.IsNoAddr()) {
        snmpOutgoingConn = new Comm::Connection;
        snmpOutgoingConn->local = Config.Addrs.snmp_outgoing;
        snmpOutgoingConn->local.SetPort(Config.Port.snmp);

        if (!Ip::EnableIpv6 && !snmpOutgoingConn->local.SetIPv4()) {
            debugs(49, DBG_CRITICAL, "ERROR: IPv6 is disabled. " << snmpOutgoingConn->local << " is not an IPv4 address.");
            fatal("SNMP port cannot be opened.");
        }
        /* split-stack for now requires IPv4-only SNMP */
        if (Ip::EnableIpv6&IPV6_SPECIAL_SPLITSTACK && snmpOutgoingConn->local.IsAnyAddr()) {
            snmpOutgoingConn->local.SetIPv4();
        }
        AsyncCall::Pointer call = asyncCall(49, 2, "snmpOutgoingConnectionOpened",
                                            SnmpListeningStartedDialer(&snmpPortOpened));
        Ipc::StartListening(SOCK_DGRAM, IPPROTO_UDP, snmpOutgoingConn, Ipc::fdnOutSnmpSocket, call);
    } else {
        snmpOutgoingConn = snmpIncomingConn;
        debugs(1, DBG_IMPORTANT, "Sending SNMP messages from " << snmpOutgoingConn->local);
    }
}

static void
snmpPortOpened(const Comm::ConnectionPointer &conn, int errNo)
{
    if (!Comm::IsConnOpen(conn))
        fatalf("Cannot open SNMP %s Port",(conn->fd == snmpIncomingConn->fd?"receiving":"sending"));

    Comm::SetSelect(conn->fd, COMM_SELECT_READ, snmpHandleUdp, NULL, 0);

    if (conn->fd == snmpIncomingConn->fd)
        debugs(1, DBG_IMPORTANT, "Accepting SNMP messages on " << snmpIncomingConn->local);
    else if (conn->fd == snmpOutgoingConn->fd)
        debugs(1, DBG_IMPORTANT, "Sending SNMP messages from " << snmpOutgoingConn->local);
    else
        fatalf("Lost SNMP port (%d) on FD %d", (int)conn->local.GetPort(), conn->fd);
}

void
snmpConnectionShutdown(void)
{
    if (!Comm::IsConnOpen(snmpIncomingConn))
        return;

    // Perform lazy closure. So as not to step on outgoing connection when sharing.
    debugs(49, DBG_IMPORTANT, "Closing SNMP receiving port " << snmpIncomingConn->local);
    snmpIncomingConn = NULL;

    /*
     * Normally we only write to the outgoing SNMP socket, but we
     * also have a read handler there to catch messages sent to that
     * specific interface.  During shutdown, we must disable reading
     * on the outgoing socket.
     */
    assert(Comm::IsConnOpen(snmpOutgoingConn));

    Comm::SetSelect(snmpOutgoingConn->fd, COMM_SELECT_READ, NULL, NULL, 0);
}

void
snmpConnectionClose(void)
{
    snmpConnectionShutdown();

    if (!Comm::IsConnOpen(snmpOutgoingConn))
        return;

    debugs(49, DBG_IMPORTANT, "Closing SNMP sending port " << snmpOutgoingConn->local);
    snmpOutgoingConn = NULL;
}

/*
