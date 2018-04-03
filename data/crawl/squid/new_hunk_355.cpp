        ErrorState *err = new ErrorState(ERR_WRITE_ERROR, Http::scBadGateway, fwd->request);
        err->xerrno = io.xerrno;
        fwd->fail(err);
        closeServer();
        mustStop("HttpStateData::wroteLast");
        return;
    }

