    entry->reset();
    fwd->fail(new ErrorState(error, Http::scBadGateway, fwd->request));
    flags.do_next_read = false;
    closeServer();
    mustStop("HttpStateData::continueAfterParsingHeader");
    return false; // quit on error
}

