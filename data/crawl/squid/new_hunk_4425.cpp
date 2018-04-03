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

