                       url);

    if (sock == COMM_ERROR) {
        debugs(26, 4, "sslStart: Failed because we're out of sockets.");
        err = errorCon(ERR_SOCKET_FAILURE, HTTP_INTERNAL_SERVER_ERROR, request);
        *status_ptr = HTTP_INTERNAL_SERVER_ERROR;
        err->xerrno = errno;
        errorSend(fd, err);
        return;
    }

    sslState = new SslStateData;
#if DELAY_POOLS

    sslState->server.setDelayId(DelayId::DelayClient(http));
#endif

    sslState->url = xstrdup(url);
    sslState->request = HTTPMSGLOCK(request);
    sslState->server.size_ptr = size_ptr;
    sslState->status_ptr = status_ptr;
    sslState->client.fd(fd);
    sslState->server.fd(sock);
    comm_add_close_handler(sslState->server.fd(),
                           sslServerClosed,
                           sslState);
    comm_add_close_handler(sslState->client.fd(),
                           sslClientClosed,
                           sslState);
    commSetTimeout(sslState->client.fd(),
                   Config.Timeout.lifetime,
                   sslTimeout,
                   sslState);
    commSetTimeout(sslState->server.fd(),
                   Config.Timeout.connect,
                   sslConnectTimeout,
                   sslState);
    peerSelect(request,
               NULL,
               sslPeerSelectComplete,
               sslState);
    /*
     * Disable the client read handler until peer selection is complete
     * Take control away from client_side.c.
     */
    commSetSelect(sslState->client.fd(), COMM_SELECT_READ, NULL, NULL, 0);
}

static void
sslProxyConnected(int fd, void *data)
{
    SslStateData *sslState = (SslStateData *)data;
    HttpHeader hdr_out(hoRequest);
    Packer p;
    http_state_flags flags;
    debugs(26, 3, "sslProxyConnected: FD " << fd << " sslState=" << sslState);
    memset(&flags, '\0', sizeof(flags));
    flags.proxying = sslState->request->flags.proxying;
    MemBuf mb;
    mb.init();
    mb.Printf("CONNECT %s HTTP/1.0\r\n", sslState->url);
    HttpStateData::httpBuildRequestHeader(sslState->request,
                                          sslState->request,
                                          NULL,			/* StoreEntry */
                                          &hdr_out,
                                          flags);			/* flags */
