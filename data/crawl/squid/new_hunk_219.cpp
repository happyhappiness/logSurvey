        return false;
    }

    // when absolute-URI is provided Host header should be ignored. However
    // some code still uses Host directly so normalize it using the previously
    // sanitized URL authority value.
    // For now preserve the case where Host is completely absent. That matters.
    if (const auto x = request->header.delById(Http::HOST)) {
        debugs(33, 5, "normalize " << x << " Host header using " << request->url.authority());
        SBuf tmp(request->url.authority());
        request->header.putStr(Http::HOST, tmp.c_str());
    }

    http->request = request.getRaw();
    HTTPMSGLOCK(http->request);

