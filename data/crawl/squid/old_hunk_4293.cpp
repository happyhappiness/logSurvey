    }
#endif

    /* append X-Forwarded-For */
    strFwd = hdr_in->getList(HDR_X_FORWARDED_FOR);

    if (opt_forwarded_for && !orig_request->client_addr.IsNoAddr()) {
        orig_request->client_addr.NtoA(bbuf,MAX_IPSTRLEN);
        strListAdd(&strFwd, bbuf, ',');
