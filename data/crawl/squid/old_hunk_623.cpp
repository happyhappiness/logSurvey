    request->flags.cachable = false; // XXX: reset later by maybeCacheable()
    request->flags.noCache = true;

    request->header.putStr(HDR_FTP_COMMAND, cmd.c_str());
    request->header.putStr(HDR_FTP_ARGUMENTS, params.c_str()); // may be ""
    if (method == Http::METHOD_PUT) {
        request->header.putStr(HDR_EXPECT, "100-continue");
        request->header.putStr(HDR_TRANSFER_ENCODING, "chunked");
    }

    ClientHttpRequest *const http = new ClientHttpRequest(this);
