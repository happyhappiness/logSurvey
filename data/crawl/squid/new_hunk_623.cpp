    request->flags.cachable = false; // XXX: reset later by maybeCacheable()
    request->flags.noCache = true;

    request->header.putStr(Http::HdrType::FTP_COMMAND, cmd.c_str());
    request->header.putStr(Http::HdrType::FTP_ARGUMENTS, params.c_str()); // may be ""
    if (method == Http::METHOD_PUT) {
        request->header.putStr(Http::HdrType::EXPECT, "100-continue");
        request->header.putStr(Http::HdrType::TRANSFER_ENCODING, "chunked");
    }

    ClientHttpRequest *const http = new ClientHttpRequest(this);
