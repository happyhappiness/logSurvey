    if (!hdr_out->has(HDR_HOST)) {
        if (request->peer_domain) {
            hdr_out->putStr(HDR_HOST, request->peer_domain);
        } else {
            SBuf authority = request->url.authority();
            hdr_out->putStr(HDR_HOST, authority.c_str());
        }
    }

