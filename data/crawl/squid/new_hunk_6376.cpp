	stringClean(&strConnection);
    }
    /* Handle Ranges */
    if (http->request->range)
	clientBuildRangeHeader(http, rep);
    /* Append X-Cache */
    httpHeaderPutStrf(hdr, HDR_X_CACHE, "%s from %s",
	is_hit ? "HIT" : "MISS", getMyHostname());
