                strFwd = orig_request->client_addr.NtoA(ntoabuf, MAX_IPSTRLEN);
        }
        if (strFwd.size() > 0)
            hdr_out->putStr(HDR_X_FORWARDED_FOR, strFwd.unsafeBuf());
    }
    /** If set to DELETE - do not copy through. */
    strFwd.clean();
