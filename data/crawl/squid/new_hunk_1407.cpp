    if (!hdr_out->has(HDR_HOST)) {
        if (request->peer_domain) {
            hdr_out->putStr(HDR_HOST, request->peer_domain);
        } else if (request->port == urlDefaultPort(request->url.getScheme())) {
            /* use port# only if not default */
            hdr_out->putStr(HDR_HOST, request->GetHost());
        } else {
