    // CONNECT response was successfully parsed
    request->hier.peer_reply_status = rep.sline.status();

    // bail if we did not get an HTTP 200 (Connection Established) response
    if (rep.sline.status() != Http::scOkay) {
        // if we ever decide to reuse the peer connection, we must extract the error response first
        *status_ptr = rep.sline.status(); // we are relaying peer response
        informUserOfPeerError("unsupported CONNECT response status code", rep.hdr_sz);
        return;
    }
