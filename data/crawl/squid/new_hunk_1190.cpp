
        if (!url) {
            hp->request_parse_status = Http::scBadRequest;
            return conn->abortRequestParsing("error:invalid-request");
        }
#endif

