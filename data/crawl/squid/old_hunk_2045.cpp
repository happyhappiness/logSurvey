
#endif

    // XXX: chunking a Content-Range response may not violate specs, but our
    // ClientSocketContext::writeComplete() confuses the end of ClientStream
    // with the end of to-client writing and may quit before writing last-chunk
    const bool maySendChunkedReply = !reply->content_range &&
                                     !request->multipartRangeRequest() &&
                                     reply->sline.protocol == AnyP::PROTO_HTTP && // response is HTTP
                                     (request->http_ver >= HttpVersion(1, 1));

    /* Check whether we should send keep-alive */
    if (!Config.onoff.error_pconns && reply->sline.status >= 400 && !request->flags.mustKeepalive()) {
        debugs(33, 3, "clientBuildReplyHeader: Error, don't keep-alive");
        request->flags.clearProxyKeepalive();
    } else if (!Config.onoff.client_pconns && !request->flags.mustKeepalive()) {
        debugs(33, 2, "clientBuildReplyHeader: Connection Keep-Alive not requested by admin or client");
        request->flags.clearProxyKeepalive();
    } else if (request->flags.proxyKeepalive() && shutting_down) {
        debugs(88, 3, "clientBuildReplyHeader: Shutting down, don't keep-alive.");
        request->flags.clearProxyKeepalive();
    } else if (request->flags.connectionAuthWanted() && !reply->keep_alive) {
        debugs(33, 2, "clientBuildReplyHeader: Connection oriented auth but server side non-persistent");
        request->flags.clearProxyKeepalive();
    } else if (reply->bodySize(request->method) < 0 && !maySendChunkedReply) {
        debugs(88, 3, "clientBuildReplyHeader: can't keep-alive, unknown body size" );
        request->flags.clearProxyKeepalive();
    } else if (fdUsageHigh()&& !request->flags.mustKeepalive()) {
        debugs(88, 3, "clientBuildReplyHeader: Not many unused FDs, can't keep-alive");
        request->flags.clearProxyKeepalive();
    } else if (request->flags.sslBumped() && !reply->persistent()) {
        // We do not really have to close, but we pretend we are a tunnel.
        debugs(88, 3, "clientBuildReplyHeader: bumped reply forces close");
        request->flags.clearProxyKeepalive();
    }

    // Decide if we send chunked reply
    if (maySendChunkedReply &&
            request->flags.proxyKeepalive() &&
            reply->bodySize(request->method) < 0) {
        debugs(88, 3, "clientBuildReplyHeader: chunked reply");
        request->flags.markReplyChunked();
        hdr->putStr(HDR_TRANSFER_ENCODING, "chunked");
    }

