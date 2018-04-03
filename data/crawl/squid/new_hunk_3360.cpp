        addr = Config.Addrs.udp_incoming;

    vc->queue = new MemBuf;
    vc->msg = new MemBuf;
    vc->busy = 1;

    Comm::Connection *conn = new Comm::Connection;
    conn->local = addr;
    conn->remote = nameservers[ns].S;

    AsyncCall::Pointer call = commCbCall(78,3, "idnsInitVCConnected", CommConnectCbPtrFun(idnsInitVCConnected, vc));

    ConnectStateData *cs = new ConnectStateData(conn, call);
    cs->host = xstrdup("DNS TCP Socket");
    cs->connect();
}

static void
