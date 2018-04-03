        debugs(31, 1, "Outgoing HTCP messages on port " << Config.Port.htcp << ", FD " << htcpOutSocket << ".");

        fd_note(htcpInSocket, "Incoming HTCP socket");
    } else {
        htcpOutSocket = htcpInSocket;
    }

    if (!htcpDetailPool) {
        htcpDetailPool = memPoolCreate("htcpDetail", sizeof(htcpDetail));
    }
}

int
htcpQuery(StoreEntry * e, HttpRequest * req, peer * p)
{
