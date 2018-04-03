        fwd->fail(new ErrorState(ERR_READ_TIMEOUT, Http::scGatewayTimeout, fwd->request));
    }

    closeServer();
    mustStop("HttpStateData::httpTimeout");
}

/// Remove an existing public store entry if the incoming response (to be
