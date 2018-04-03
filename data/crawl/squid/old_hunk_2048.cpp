         */
        if (request->peer_domain)
            hdr_out->putStr(HDR_HOST, request->peer_domain);
        else if (request->flags.isRedirected() && !Config.onoff.redir_rewrites_host)
            hdr_out->addEntry(e->clone());
        else {
            /* use port# only if not default */
