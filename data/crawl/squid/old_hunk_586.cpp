        return;

    // TODO: bypass if possible

    if (entry->isEmpty()) {
        debugs(11,9, HERE << "creating ICAP error entry after ICAP failure");
        ErrorState *err = new ErrorState(ERR_ICAP_FAILURE, Http::scInternalServerError, request);
        err->detailError(ERR_DETAIL_ICAP_RESPMOD_EARLY);
        fwd->fail(err);
        fwd->dontRetry(true);
    } else if (request) { // update logged info directly
        request->detailError(ERR_ICAP_FAILURE, ERR_DETAIL_ICAP_RESPMOD_LATE);
    }

    abortTransaction("ICAP failure");
}

// adaptation service wants us to deny HTTP client access to this response
