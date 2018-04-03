    }

    const HttpRequestMethod method =
        !cmd.caseCmp("APPE") || !cmd.caseCmp("STOR") || !cmd.caseCmp("STOU") ?
        Http::METHOD_PUT : Http::METHOD_GET;

    const char *aPath = params.size() > 0 && CommandHasPathParameter(cmd) ?
        params.termedBuf() : NULL;
    calcUri(aPath);
    char *newUri = xstrdup(uri.termedBuf());
    HttpRequest *const request = HttpRequest::CreateFromUrlAndMethod(newUri, method);
    if (!request) {
        debugs(33, 5, "Invalid FTP URL: " << uri);
        writeEarlyReply(501, "Invalid host");
        uri.clean();
        safe_free(newUri);
        return NULL;
    }

    request->flags.ftpNative = true;
    request->http_ver = ver;

    // Our fake Request-URIs are not distinctive enough for caching to work
    request->flags.cachable = false; // XXX: reset later by maybeCacheable()
    request->flags.noCache = true;

    request->header.putStr(HDR_FTP_COMMAND, cmd.termedBuf());
    request->header.putStr(HDR_FTP_ARGUMENTS, params.termedBuf() != NULL ?
                           params.termedBuf() : "");
    if (method == Http::METHOD_PUT) {
        request->header.putStr(HDR_EXPECT, "100-continue");
        request->header.putStr(HDR_TRANSFER_ENCODING, "chunked");
