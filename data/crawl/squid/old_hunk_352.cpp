        fwd->fail(new ErrorState(ERR_READ_TIMEOUT, Http::scGatewayTimeout, fwd->request));
    }

    serverConnection->close();
}

/// Remove an existing public store entry if the incoming response (to be
