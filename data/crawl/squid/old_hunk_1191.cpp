    } else if ( (size_t)hp->bufsiz >= Config.maxRequestHeaderSize && headersEnd(hp->buf, Config.maxRequestHeaderSize) == 0) {
        debugs(33, 5, "parseHttpRequest: Too large request");
        hp->request_parse_status = Http::scHeaderTooLarge;
        return parseHttpRequestAbort(csd, "error:request-too-large");
    }

    /* Attempt to parse the first line; this'll define the method, url, version and header begin */
