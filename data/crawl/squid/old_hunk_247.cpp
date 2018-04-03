    }

    // Decide if we send chunked reply
    if (maySendChunkedReply &&
            request->flags.proxyKeepalive &&
            reply->bodySize(request->method) < 0) {
        debugs(88, 3, "clientBuildReplyHeader: chunked reply");
        request->flags.chunkedReply = true;
        hdr->putStr(Http::HdrType::TRANSFER_ENCODING, "chunked");
