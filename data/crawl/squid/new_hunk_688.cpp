        else if (request->flags.redirected && !Config.onoff.redir_rewrites_host)
            hdr_out->addEntry(e->clone());
        else {
            SBuf authority = request->url.authority();
            hdr_out->putStr(HDR_HOST, authority.c_str());
        }

        break;
