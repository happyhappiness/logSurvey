         * went through our redirector and the admin configured
         * 'redir_rewrites_host' to be off.
         */

        if (request->flags.redirected && !Config.onoff.redir_rewrites_host)
            hdr_out->addEntry(e->clone());
        else {
            /* use port# only if not default */