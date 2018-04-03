    entry->reset();
    fwd->fail(new ErrorState(error, Http::scBadGateway, fwd->request));
    flags.do_next_read = false;
    serverConnection->close();
    return false; // quit on error
}

