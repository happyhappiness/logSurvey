
    /* append Host if not there already */
    if (!hdr_out->has(HDR_HOST)) {
        if (orig_request->peer_domain) {
            hdr_out->putStr(HDR_HOST, orig_request->peer_domain);
        } else if (orig_request->port == urlDefaultPort(orig_request->protocol)) {
            /* use port# only if not default */
            hdr_out->putStr(HDR_HOST, orig_request->GetHost());
        } else {
            httpHeaderPutStrf(hdr_out, HDR_HOST, "%s:%d",
                              orig_request->GetHost(),
                              (int) orig_request->port);
        }
    }

    /* append Authorization if known in URL, not in header and going direct */
    if (!hdr_out->has(HDR_AUTHORIZATION)) {
        if (!request->flags.proxying && *request->login) {
            httpHeaderPutStrf(hdr_out, HDR_AUTHORIZATION, "Basic %s",
                              old_base64_encode(request->login));
        }
    }

    /* Fixup (Proxy-)Authorization special cases. Plain relaying dealt with above */
    httpFixupAuthentication(request, orig_request, hdr_in, hdr_out, flags);

    /* append Cache-Control, add max-age if not there already */
    {
