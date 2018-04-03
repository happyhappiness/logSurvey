}

void
Http::One::Server::writeControlMsgAndCall(HttpReply *rep, AsyncCall::Pointer &call)
{
    // apply selected clientReplyContext::buildReplyHeader() mods
    // it is not clear what headers are required for control messages
    rep->header.removeHopByHopEntries();
    rep->header.putStr(Http::HdrType::CONNECTION, "keep-alive");
    httpHdrMangleList(&rep->header, pipeline.front()->http->request, ROR_REPLY);

    MemBuf *mb = rep->pack();

    debugs(11, 2, "HTTP Client " << clientConnection);
    debugs(11, 2, "HTTP Client CONTROL MSG:\n---------\n" << mb->buf << "\n----------");

    Comm::Write(clientConnection, mb, call);

    delete mb;
}
