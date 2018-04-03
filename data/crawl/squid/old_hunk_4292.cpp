            hdr_out->putStr(HDR_X_FORWARDED_FOR, strFwd.buf());
    }
    /** If set to DELETE - do not copy through. */

#else

    if (opt_forwarded_for && !orig_request->client_addr.IsNoAddr()) {
        orig_request->client_addr.NtoA(bbuf,MAX_IPSTRLEN);
        strListAdd(&strFwd, bbuf, ',');
    }
    else
        strListAdd(&strFwd, "unknown", ',');

    hdr_out->putStr(HDR_X_FORWARDED_FOR, strFwd.buf());

#endif
    strFwd.clean();

    /* append Host if not there already */