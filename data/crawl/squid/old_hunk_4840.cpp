         */

        if (request->flags.redirected && !Config.onoff.redir_rewrites_host)
            httpHeaderAddEntry(hdr_out, httpHeaderEntryClone(e));
        else {
            /* use port# only if not default */

            if (orig_request->port == urlDefaultPort(orig_request->protocol)) {
                httpHeaderPutStr(hdr_out, HDR_HOST, orig_request->host);
            } else {
                httpHeaderPutStrf(hdr_out, HDR_HOST, "%s:%d",
                                  orig_request->host, (int) orig_request->port);