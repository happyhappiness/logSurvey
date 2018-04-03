        request->header.putStr(Http::HOST, tmp.c_str());
    }

    // TODO: We fill request notes here until we find a way to verify whether
    // no ACL checking is performed before ClientHttpRequest::doCallouts().
    if (hasNotes()) {
        assert(!request->hasNotes());
        request->notes()->append(notes().getRaw());
    }

    http->request = request.getRaw();
    HTTPMSGLOCK(http->request);

