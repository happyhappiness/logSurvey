    socklen_t len;
    int x;

	debug(49, 5) ("snmpConnectionOpen: Called\n");
    if ((port = Config.Port.snmp) > (u_short) 0) {
        enter_suid();
        theInSnmpConnection = comm_open(SOCK_DGRAM,
            0,
            Config.Addrs.snmp_incoming,
            port,
            COMM_NONBLOCKING,
            "SNMP Port");
        leave_suid();
        if (theInSnmpConnection < 0)
            fatal("Cannot open snmp Port");
        commSetSelect(theInSnmpConnection, COMM_SELECT_READ, snmpHandleUdp, NULL, 0);
        debug(1, 1) ("Accepting SNMP messages on port %d, FD %d.\n",
            (int) port, theInSnmpConnection);
        if (Config.Addrs.snmp_outgoing.s_addr != no_addr.s_addr) {
            enter_suid();
            theOutSnmpConnection = comm_open(SOCK_DGRAM,
                0,
                Config.Addrs.snmp_outgoing,
                port,
                COMM_NONBLOCKING,
                "SNMP Port");
            leave_suid();
            if (theOutSnmpConnection < 0)
                fatal("Cannot open Outgoing SNMP Port");
            commSetSelect(theOutSnmpConnection,
                COMM_SELECT_READ,
                snmpHandleUdp,
                NULL, 0);
            debug(1, 1) ("Outgoing SNMP messages on port %d, FD %d.\n",
                (int) port, theOutSnmpConnection);
            fd_note(theOutSnmpConnection, "Outgoing SNMP socket");
            fd_note(theInSnmpConnection, "Incoming SNMP socket");
        } else {
            theOutSnmpConnection = theInSnmpConnection;
        }
        memset(&theOutSNMPAddr, '\0', sizeof(struct in_addr));
        len = sizeof(struct sockaddr_in);
        memset(&xaddr, '\0', len);
        x = getsockname(theOutSnmpConnection,
            (struct sockaddr *) &xaddr, &len);
        if (x < 0)
            debug(51, 1) ("theOutSnmpConnection FD %d: getsockname: %s\n",
                theOutSnmpConnection, xstrerror());
        else 
            theOutSNMPAddr = xaddr.sin_addr;
    }
}

void
snmpConnectionShutdown(void)
{
    if (theInSnmpConnection < 0)
        return;
    if (theInSnmpConnection != theOutSnmpConnection) {
        debug(49, 1) ("FD %d Closing SNMP socket\n", theInSnmpConnection);
        comm_close(theInSnmpConnection);
    }
    /*
     * Here we set 'theInSnmpConnection' to -1 even though the SNMP 'in'
