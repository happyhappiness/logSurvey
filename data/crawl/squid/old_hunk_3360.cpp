        addr = Config.Addrs.udp_incoming;

    vc->queue = new MemBuf;

    vc->msg = new MemBuf;

    vc->fd = comm_open(SOCK_STREAM,
                       IPPROTO_TCP,
                       addr,
                       COMM_NONBLOCKING,
                       "DNS TCP Socket");

    if (vc->fd < 0)
        fatal("Could not create a DNS socket");

    comm_add_close_handler(vc->fd, idnsVCClosed, vc);

    vc->busy = 1;

    commConnectStart(vc->fd, nameservers[ns].S.NtoA(buf,MAX_IPSTRLEN), nameservers[ns].S.GetPort(), idnsInitVCConnected, vc);
}

static void
