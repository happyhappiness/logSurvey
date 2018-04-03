        request->header.putStr(Http::HOST, tmp.c_str());
    }

    http->request = request.getRaw();
    HTTPMSGLOCK(http->request);

