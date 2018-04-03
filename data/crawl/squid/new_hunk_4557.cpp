                       url);

    if (sock == COMM_ERROR) {
        debugs(26, 4, "tunnelStart: Failed because we're out of sockets.");
        err = errorCon(ERR_SOCKET_FAILURE, HTTP_INTERNAL_SERVER_ERROR, request);
        *status_ptr = HTTP_INTERNAL_SERVER_ERROR;
        err->xerrno = errno;
        errorSend(fd, err);
        return;
    }

    tunnelState = new SslStateData;
#if DELAY_POOLS

    tunnelState->server.setDelayId(DelayId::DelayClient(http));
#endif

    tunnelState->url = xstrdup(url);
    tunnelState->request = HTTPMSGLOCK(request);
    tunnelState->server.size_ptr = size_ptr;
    tunnelState->status_ptr = status_ptr;
    tunnelState->client.fd(fd);
    tunnelState->server.fd(sock);
    comm_add_close_handler(tunnelState->server.fd(),
                           tunnelServerClosed,
                           tunnelState);
    comm_add_close_handler(tunnelState->client.fd(),
                           tunnelClientClosed,
                           tunnelState);
    commSetTimeout(tunnelState->client.fd(),
                   Config.Timeout.lifetime,
                   tunnelTimeout,
                   tunnelState);
    commSetTimeout(tunnelState->server.fd(),
                   Config.Timeout.connect,
                   tunnelConnectTimeout,
                   tunnelState);
    peerSelect(request,
               NULL,
               tunnelPeerSelectComplete,
               tunnelState);
    /*
     * Disable the client read handler until peer selection is complete
     * Take control away from client_side.c.
     */
    commSetSelect(tunnelState->client.fd(), COMM_SELECT_READ, NULL, NULL, 0);
}

static void
tunnelProxyConnected(int fd, void *data)
{
    SslStateData *tunnelState = (SslStateData *)data;
    HttpHeader hdr_out(hoRequest);
    Packer p;
    http_state_flags flags;
    debugs(26, 3, "tunnelProxyConnected: FD " << fd << " tunnelState=" << tunnelState);
    memset(&flags, '\0', sizeof(flags));
    flags.proxying = tunnelState->request->flags.proxying;
    MemBuf mb;
    mb.init();
    mb.Printf("CONNECT %s HTTP/1.0\r\n", tunnelState->url);
    HttpStateData::httpBuildRequestHeader(tunnelState->request,
                                          tunnelState->request,
                                          NULL,			/* StoreEntry */
                                          &hdr_out,
                                          flags);			/* flags */
