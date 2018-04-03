    if (req_sz >= Config.maxRequestHeaderSize) {
        debugs(33, 5, "parseHttpRequest: Too large request");
        hp->request_parse_status = Http::scHeaderTooLarge;
        return csd->abortRequestParsing("error:request-too-large");
    }

    /* Set method_p */
