void
Http::One::Server::writeControlMsgAndCall(HttpReply *rep, AsyncCall::Pointer &call)
{
    const ClientHttpRequest *http = pipeline.front()->http;

    // apply selected clientReplyContext::buildReplyHeader() mods
    // it is not clear what headers are required for control messages
    rep->header.removeHopByHopEntries();
    rep->header.putStr(Http::HdrType::CONNECTION, "keep-alive");
    httpHdrMangleList(&rep->header, http->request, http->al, ROR_REPLY);

    MemBuf *mb = rep->pack();

