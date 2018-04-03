
        iaddr.SetPort(port);

        if (client_comm_connect(conn, iaddr, ping ? &tv1 : NULL) < 0) {
            char hostnameBuf[MAX_IPSTRLEN];
            iaddr.ToURL(hostnameBuf, MAX_IPSTRLEN);
