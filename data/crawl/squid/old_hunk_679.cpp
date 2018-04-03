
    // bail if we did not get an HTTP 200 (Connection Established) response
    if (rep.sline.status() != Http::scOkay) {
        server.logicError("unsupported CONNECT response status code");
        return;
    }

