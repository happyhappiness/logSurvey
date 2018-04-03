    if ( !addr.IsNoAddr() ) {
        enter_suid();
        addr.SetPort(port);
        theOutIcpConnection = comm_open_listener(SOCK_DGRAM,
                              IPPROTO_UDP,
                              addr,
