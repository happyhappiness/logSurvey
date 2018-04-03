        err->detailError(ERR_DETAIL_ICAP_RESPMOD_EARLY);
        fwd->fail(err);
        fwd->dontRetry(true);
        abortAll("adaptation failure with an empty entry");
        return true; // handled
    }

