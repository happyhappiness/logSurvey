{

    if (theInitiator.set()) {
        clearInitiator();
        detailError(ERR_DETAIL_ICAP_INIT_GONE);
        mustStop("initiator aborted");
    }

