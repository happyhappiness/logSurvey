
        if (!url) {
            hp->request_parse_status = Http::scBadRequest;
            return parseHttpRequestAbort(conn, "error:invalid-request");
        }
#endif

